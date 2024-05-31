#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "guitar.h"

namespace seneca
{
	Guitar::Guitar(const char* model)
	{
		m_cntStrings = 0;
		m_strings = nullptr;
		if (model != NULL)
		{
			std::strcpy(m_model, model);
		}
		else
		{
			m_model[0] = '\0';
		}
	}

	Guitar::Guitar(const GuitarString* strings, int cntStrings, const char* model)
	{
		*this = Guitar(model);
		bool isValid = (m_model != NULL && strings != nullptr && cntStrings >= 0); 
		if (isValid)
		{
			// Set the array of GuitarString
			m_cntStrings = cntStrings;
			m_strings = new GuitarString[m_cntStrings];
			for (int i = 0; i < m_cntStrings; i++)
			{
				m_strings[i] = strings[i];
			}
		}
	}

	Guitar& Guitar::reString(const GuitarString* strings, int cntStrings)
	{
		delete[] m_strings;
		m_cntStrings = cntStrings;
		m_strings = new GuitarString[cntStrings];
		for (int i = 0; i < cntStrings; i++)
		{
			m_strings[i] = strings[i];
		}
		
		return *this; // reference of the current object
	}

	Guitar& Guitar::reString(const GuitarString& aString, int idx)
	{
		m_strings[idx] = aString;
		return *this;
	}

	Guitar& Guitar::deString()
	{
		delete[] m_strings;
		m_strings = nullptr;
		m_cntStrings = 0;
		return *this;
	}

	bool Guitar::isStrung() const
	{
		if (m_cntStrings > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	std::ostream& Guitar::display(std::ostream& out) const
	{
		if (m_model[0] == '\0')
		{
			out << "Empty guitar object!" << std::endl;
		}
		else if (m_cntStrings == 0 && m_model != NULL)
		{
			out << "Guitar Model: " << m_model << std::endl;
			out << "Guitar cannot be used yet because it has no strings." << std::endl;
		}
		else
		{
			out << "Guitar Model: " << m_model << std::endl;
			out << "Strings:" << std::endl;
			for (int i = 0; i < m_cntStrings; i++)
			{
				out << " #" << i + 1 << ". " << m_strings[i].getMaterial() << " (" << m_strings[i].getGauge() << "mm)" << std::endl;
			}
		}
		return out;
	}

	Guitar::~Guitar()
	{
		if (m_cntStrings > 0) // only de-allocate memory if the Guitar has any GuitarStrings
		{
			delete[] m_strings;
			m_strings = nullptr;
		}
		m_cntStrings = 0;
	}

	



}
