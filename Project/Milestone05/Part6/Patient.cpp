/* Citation and Sources...
Final Project Milestone 5, Part 6
Module: Patient
Filename: Patient.cpp
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/03/30  Added clear buffer to end of read function
2024/03/27  Preliminary release
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"

using namespace std;
namespace seneca
{
	// initialized m_ticket via Member Initializer List (since Ticket doesn't have a default constructor)
	
	Patient::Patient(int ticketNum): m_ticket(ticketNum) 
	{
		m_name = nullptr;
		m_ohipNumber = 0;
	}

	Patient::Patient(const Patient& patient): m_ticket(patient.m_ticket.number())
	{
		m_name = nullptr;
		*this = patient;
	}

	Patient& Patient::operator=(const Patient& patient)
	{
		if (this != &patient)
		{
			delete[] m_name;

			m_ohipNumber = patient.m_ohipNumber;
			m_ticket = patient.m_ticket;
			if (patient.m_name != nullptr)
			{
				m_name = new char[strlen(patient.m_name) + 1]{};
				std::strcpy(m_name, patient.m_name);
			}
			else
			{
				m_name = nullptr;
			}
		}
		return *this;
	}

	Patient::~Patient()
	{
		delete[] m_name;
	}
	
	bool Patient::operator==(char type) const
	{
		if (type == this->type())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Patient::operator==(const Patient& patient) const
	{
		if (this->type() == patient.type())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}

	Time Patient::time() const
	{
		return m_ticket.time();
	}

	int Patient::number() const
	{
		return m_ticket.number();
	}

	Patient::operator bool() const
	{
		bool isValid = (m_name != nullptr && m_ohipNumber >= 0  && m_ticket.number() > 0 
			            && m_ticket.time() > 0);
		return isValid;
	}

	Patient::operator const char* () const
	{
		return m_name;
	}

	std::ostream& Patient::write(ostream& ostr) const
	{
		if (&ostr == &clog)
		{
			if (!(*this))
			{
				ostr << "Invalid Patient Record" << endl;
			}
			else
			{
				ostr.width(53);
				auto oldFill = ostr.fill('.');
				ostr.setf(ios::left);
				ostr << m_name;
				ostr.unsetf(ios::left);
				ostr.fill(' ');
				ostr << m_ohipNumber;
				ostr.width(5);
				ostr << number();
				ostr << " ";
				ostr << time();
				ostr.fill(oldFill);
			}
		}
		else if (&ostr == &cout)
		{
			if (!(*this))
			{
				ostr << "Invalid Patient Record" << endl;
			}
			else
			{
				ostr << m_ticket << endl;
				ostr << m_name << ", OHIP: " << m_ohipNumber << endl;
			}
		}
		else
		{
			ostr << type() << "," << m_name << "," << m_ohipNumber << ",";
			m_ticket.write(ostr);
		}

		return ostr;
	}

	std::istream& Patient::read(istream& istr)
	{
		if (&istr == &cin)
		{
			std::cout << "Name: ";
			char name[51] = {};
			istr.get(name, 50 + 1, '\n');
			delete[] m_name;
			m_name = new char[strlen(name) + 1];
			std::strcpy(m_name, name);
			istr.ignore(10000, '\n');
			bool done = false;
			std::cout << "OHIP: ";
			do {
				istr >> m_ohipNumber;
				bool isValid = (m_ohipNumber >= 100000000 && m_ohipNumber <= 999999999);
				if (istr.fail())
				{
					istr.clear();
					istr.ignore(10000, '\n');
					done = false;
					std::cout << "Bad integer value, try again: ";
				}
				else if (!isValid)
				{
					done = false;
					std::cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
					istr.ignore();
				}
				else
				{
					done = true;
				}
			} while (!done);
			istr.clear();
			istr.ignore(10000, '\n');
		}
		else if (istr.fail())
		{
			delete[] m_name;
			m_name = nullptr;
		}
		else
		{
			char name[51] = {};
			istr.get(name, 50 + 1, ',');
			delete[] m_name;
			m_name = new char[strlen(name) + 1]{};
			std::strcpy(m_name, name);
			istr.ignore(10000, ','); // ignore params - how many characters to ignore, delimeter
			istr >> m_ohipNumber;
			istr.ignore(10000, ',');
			m_ticket.read(istr);
		}
		return istr;
	}
}
