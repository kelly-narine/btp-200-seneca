#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "car.h"

namespace seneca
{
	bool Car::isEmpty()
	{
		if (m_makeModel == NULL)
			return true;
		else
			return false;
	}

	void Car::setEmpty()
	{
		m_licencePlate[0] = '\0'; 
		m_makeModel = nullptr;
		m_problemDesc = nullptr;
		m_cost = 0;
		m_objectStatus = INVALID_REASON__EMPTY;
	}

	void Car::set(const char* plateNo, const char* model, const char* desc, double serviceCost)
	{
		deallocateMemory();

		//validation of paramters
		if (plateNo == nullptr || plateNo[0] == '\0')
		{
			m_objectStatus = INVALID_REASON__PLATE;
		}	
		else if (model == nullptr || model[0] == '\0')
		{
			m_objectStatus = INVALID_REASON__MODEL;
		}
		else if (desc == nullptr || desc[0] == '\0')
		{
			m_objectStatus = INVALID_REASON__DESC;
		}
		else // if data provided by client is valid
		{
			std::strncpy(m_licencePlate, plateNo, 9);
			
			int numChar = 0;
			while (model[numChar] != '\0')
			{
				numChar++;
			}
			m_makeModel = new char[numChar + 1];
			std::strcpy(m_makeModel, model);
			
			numChar = 0;
			while (desc[numChar] != '\0')
			{
				numChar++;
			}
			m_problemDesc = new char[numChar + 1];
			std::strcpy(m_problemDesc, desc);
		
			m_cost = serviceCost;

			m_objectStatus = VALID_OBJECT;
		}
	}

	void Car::display() const // const added since this function is a query, denotes that content of object cannot be altered
	{
		if (m_objectStatus == VALID_OBJECT)
		{
			std::cout << "| ";
			std::cout.width(8);		
			auto oldFill = std::cout.fill(' '); // orignal 
			std::cout << m_licencePlate;
			std::cout << " | ";
			std::cout.width(20);
			std::cout.fill('.');
			std::cout.setf(std::ios::left);
			std::cout << m_makeModel;
			std::cout.unsetf(std::ios::left);
			std::cout << " | ";
			std::cout.width(40);
			std::cout << m_problemDesc;
			std::cout << " | ";
			std::cout.width(8);
			std::cout.setf(std::ios::fixed);
			auto oldPrecision = std::cout.precision(2);
			std::cout << m_cost;
			std::cout.unsetf(std::ios::fixed);
			std::cout << " |";
			std::cout.fill(oldFill); // restore original to character fill set in main
			std::cout.precision(oldPrecision); // restore to original character precision set in main	
		}
		else
		{
			std::cout << "| ";
			std::cout.width(85);
			auto oldFill = std::cout.fill(' ');
			std::cout.setf(std::ios::left);
			std::cout << m_objectStatus;
			std::cout.unsetf(std::ios::left);
			std::cout << " |";
			std::cout.fill(oldFill);
		}
	}

	void Car::deallocateMemory()
	{
		delete[] m_makeModel;
		delete[] m_problemDesc;
		setEmpty();
	}
}
