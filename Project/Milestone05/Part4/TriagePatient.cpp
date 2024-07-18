/* Citation and Sources...
Final Project Milestone 5, Part 4
Module: TriaggePatient
Filename: TriagePatient.cpp
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/04/03  Added Copy-Constructor and Copy-Assignment Operator implementation
2024/03/31  Preliminary release
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TriagePatient.h"
namespace seneca
{
	/// <summary>
	/// Global variable to determine the next Ticket number
	/// </summary>
	int g_nextTriageTicket = 1;

	TriagePatient::TriagePatient() : Patient(g_nextTriageTicket++)
	{
		m_symptoms = nullptr;
	}

	char TriagePatient::type() const
	{
		return 'T';
	}

	std::ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (&ostr == &std::cout)
		{
			ostr << "TRIAGE" << std::endl;
			Patient::write(ostr);
			ostr << "Symptoms: " << m_symptoms << std::endl;
		}
		else if (&ostr != &std::clog && &ostr != &std::cout)
		{
			Patient::write(ostr);
			ostr << "," << m_symptoms;
		}
		else
		{
			Patient::write(ostr);
		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr)
	{
		if (&istr == &std::cin)
		{
			Patient::read(istr);
			std::cout << "Symptoms: ";
			char symptoms[512] = {};
			istr.get(symptoms, 511 + 1, '\n');
			delete[] m_symptoms;
			m_symptoms = new char[std::strlen(symptoms) + 1]{};
			std::strcpy(m_symptoms, symptoms);
			istr.clear();
			istr.ignore(10000, '\n');
		}
		else if (istr.fail())
		{
			delete[] m_symptoms;
			m_symptoms = nullptr;
		}
		else
		{
			Patient::read(istr);
			istr.ignore(10000, ',');
			char symptoms[512] = {};
			istr.get(symptoms, 511 + 1, '\n');
			delete[] m_symptoms;
			m_symptoms = new char[std::strlen(symptoms) + 1]{};
			std::strcpy(m_symptoms, symptoms);
			g_nextTriageTicket = Patient::number() + 1;
		}
		return istr;
	}

	TriagePatient::TriagePatient(const TriagePatient& trgP) : Patient(trgP)
	{
		m_symptoms = nullptr;
		*this = trgP;
	}

	TriagePatient& TriagePatient::operator=(const TriagePatient& trgP)
	{
		if (this != &trgP)
		{
			(Patient&)*this = trgP;
			
			delete[] m_symptoms;

			if (trgP.m_symptoms != nullptr)
			{
				m_symptoms = new char[std::strlen(trgP.m_symptoms) + 1]{};
				std::strcpy(m_symptoms, trgP.m_symptoms);
			}
			else
			{
				m_symptoms = nullptr;
			}
		}
		return *this;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symptoms;
	}
}
