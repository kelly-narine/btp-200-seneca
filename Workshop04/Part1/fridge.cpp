#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "fridge.h"

namespace seneca
{
	Fridge::Fridge() 
	{
		m_capacity = 0;
		m_model = nullptr;
		m_food = nullptr;
		m_cntFoods = 0;
	}

	Fridge::Fridge(const char* model, int capacity)
	{
		*this = Fridge();
		setModel(model, capacity);
	}

	Fridge::Fridge(const Food* foods, int cntFoods, const char* model, int capacity)
	{
		*this = Fridge();
		setModel(model, capacity);

		if (m_model != NULL)
		{
			for (int i = 0; i < cntFoods; i++)
			{
				addFood(foods[i]);
			}
		}
	}

	void Fridge::setModel(const char* model, int capacity)
	{
		if (model[0] != '\0' && capacity >= 10)
		{
			delete[] m_model;
			m_model = nullptr;
			int numChar = 0;
			while (model[numChar] != '\0')
			{
				numChar++;
			}
			m_model = new char[numChar + 1];
			std::strcpy(m_model, model);
			m_capacity = capacity;
		}
	}

	bool Fridge::addFood(const Food& aFood)
	{
		if ((getContentWeight() + aFood.m_weight) <= m_capacity)
		{
			Food* tempFood = new Food[m_cntFoods + 1];
			if (m_food != nullptr) // if the fridge already have food in it
			{
				for (int i = 0; i < m_cntFoods; i++)
				{
					tempFood[i] = m_food[i];
				}
			}
			tempFood[m_cntFoods] = aFood;
			delete[] m_food;
			m_food = tempFood;
			m_cntFoods++;
			return true;
		}
		else
		{
			return false;
		}
	}

	int Fridge::getContentWeight() const
	{
		int totalWeight = 0;
		for (int i = 0; i < m_cntFoods; i++)
		{
			totalWeight += m_food[i].m_weight;
		}

		return totalWeight;
	}

	bool Fridge::isFull() const
	{
		if (getContentWeight() >= (0.9 * (double) m_capacity))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Fridge::hasFood(const char* theFood) const
	{
		bool hasFood = false;
		if (theFood == NULL && m_cntFoods > 0)
		{
			hasFood = true;
		}
		else
		{
			int i = m_cntFoods - 1;
			while (i > -1)
			{
				const char* existingFood = m_food[i].m_name;
				hasFood = (strcmp(existingFood, theFood) == 0); // check if specified food is already in fridge
				if (hasFood)
				{
					break;
				}
				i--;
			}
		}
		return hasFood;
	}

	void Fridge::display(std::ostream& out) const
	{
		if (m_model == NULL)
		{
			out << "The fridge object is in an empty state.\n";
		}
		else
		{
			//out.fill(' ');

			out.width(19);
			out << "Fridge model: " << m_model << std::endl;
			out.width(19);
			out << "Fridge capacity: " << m_capacity << "kg" << std::endl;
			out.width(19);
			out << "Fill percentage: " << (getContentWeight() / (double) m_capacity) * 100 << "% full" << std::endl;
			
			out << "The list of foods:" << std::endl;
			
			for (int i = 0; i < m_cntFoods; i++)
			{
				out.width(4); //width will only apply to the statement/line below
				out << "- ";
				out << m_food[i].m_name << " (" << m_food[i].m_weight << "kg)";
				out << std::endl;
			}
		}
	}

	Fridge::~Fridge()
	{
		delete[] m_model;
		m_model = nullptr;

		delete[] m_food;
		m_food = nullptr;
	}
}
