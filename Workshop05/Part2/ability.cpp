#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "ability.h"
namespace seneca
{
	Ability::Ability()
	{
		m_name[0] = '\0';
		m_strength = 0;
	}

	Ability::Ability(const char* name, int strength)
	{
		std::strcpy(m_name, name);
		m_strength = strength;
	}

	int Ability::getStrength() const
	{
		return m_strength;
	}

	const char* Ability::getAbilityName() const
	{
		return m_name;
	}
}
