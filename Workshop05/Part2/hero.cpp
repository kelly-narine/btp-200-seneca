#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "hero.h"

namespace seneca
{
	Hero::Hero()
	{
		m_name[0] = '\0';
		m_abilities = nullptr;
		m_cntAbilities = 0;
		m_level = 0;
	}

	Hero::Hero(const char* name, const Ability* abilities, int cntAbilities)
	{
		m_level = 1;
		bool isValid = (name[0] != '\0' && abilities != nullptr && cntAbilities > 0);
		if (isValid)
		{
			std::strcpy(m_name, name);
			m_cntAbilities = cntAbilities;
			m_abilities = new Ability[m_cntAbilities];
			for (int i = 0; i < m_cntAbilities; i++)
			{
				m_abilities[i] = abilities[i];
			}
		}
		else
		{
			*this = Hero();
		}
	}

	Hero::operator const char* () const
	{
		return m_name;
	}

	Hero::operator int() const
	{
		int totalStrength = 0;
		for (int i = 0; i < m_cntAbilities; i++)
		{
			totalStrength += m_abilities[i].getStrength();
		}
		totalStrength *= m_level;
		return totalStrength;
	}

	Hero& Hero::operator += (const Ability& ability)
	{
		Ability* tempAbilities = new Ability[m_cntAbilities + 1];
		for (int i = 0; i < m_cntAbilities; i++)
		{
			tempAbilities[i] = m_abilities[i];
		}
		tempAbilities[m_cntAbilities] = ability; 

		delete[] m_abilities;
		m_cntAbilities++;
		m_abilities = new Ability[m_cntAbilities];
		for (int i = 0; i < m_cntAbilities; i++)
		{
			m_abilities[i] = tempAbilities[i];
		}
		delete[] tempAbilities; // delete here as it will not go out of scope automatically
		return *this;
	}

	Hero& Hero::operator += (int lvlChange)
	{
		m_level += lvlChange;
		if (m_level < 1)
		{
			m_level = 1;
		}

		return *this;
	}

	Hero& Hero::operator++()
	{
		m_level++;
		return *this;
	}

	void Hero::display() const
	{
		std::cout << (const char*)*this << " (lvl: " << m_level << ", str: " << (int)*this << ")" << std::endl;
		for (int i = 0; i < m_cntAbilities; i++)
		{
			std::cout << "  - " << m_abilities[i].getAbilityName() << " (" << m_abilities[i].getStrength() << ")" << std::endl;
		}
	}

	Hero::~Hero()
	{
		delete[] m_abilities;
		m_abilities = nullptr;
		m_cntAbilities = 0;
	}

	bool operator < (const Hero& h1, const Hero& h2)
	{
		
		if ((int)h1 < (int)h2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator > (const Hero& h1, const Hero& h2)
	{
		if (h1 < h2)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void operator >> (const Ability& ability, Hero& hero)
	{
		hero += ability;
	}

	void operator << (Hero& hero, const Ability& ability)
	{
		ability >> hero;
	}
}
