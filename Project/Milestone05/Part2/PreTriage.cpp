/* Citation and Sources...
Final Project Milestone 5, Part 2
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/04/08  Preliminary release
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "PreTriage.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Menu.h"

namespace seneca
{
	PreTriage::PreTriage(const char* fileName) : m_testWaitTime(15), m_triageWaitTime(5)
	{
		m_fileName = new char[std::strlen(fileName) + 1];
		std::strcpy(m_fileName, fileName);
		//initializes each pointer to Patient object to nullptr
		for (int i = 0; i < MAX_PATIENTS; i++)
		{
			m_patientLineup[i] = nullptr;
		}
		m_numPatients = 0;
		load();
	}

	void PreTriage::load()
	{
		std::cout << "Loading data..." << std::endl;
		std::ifstream in(m_fileName);
		if (!in)
		{
			std::cout << "No data or bad data file" << std::endl << std::endl;
			m_numPatients = 0;
		}
		else
		{
			m_testWaitTime.read(in);
			in.ignore(10000, ','); 
			m_triageWaitTime.read(in);
			in.ignore(10000, '\n'); 
			Patient* patient = nullptr;
			char type = '\0';
			for (int i = 0; !in.eof() && i < MAX_PATIENTS; i++) 
			{
				patient = nullptr; // resets (values need to be resetted after each iteration as previous iteration's value would otherwise be left)
				type = '\0'; // resets
				//in.get(type);
				in >> type;
				in.ignore(10000, ',');
				if (type == 'C')
				{
					patient = new TestPatient();
				}
				else if (type == 'T')
				{
					patient = new TriagePatient();
				}

				if (patient != nullptr) // if the instantiation of a patient pointer sucessful
				{
					patient->read(in);
					m_patientLineup[m_numPatients] = patient;
					m_numPatients++;
					if (m_numPatients == MAX_PATIENTS && in.peek() == '\n')
					{
						std::cout << "Warning: number of records exceeded " << MAX_PATIENTS << std::endl;
						break;
					}
				}
			}
			if (m_numPatients == 0)
			{
				std::cout << "No data or bad data file!" << std::endl << std::endl;
			}
			else
			{
				std::cout << m_numPatients << " Records imported..." << std::endl << std::endl;
			}
		}
	}

	void PreTriage::save() const
	{
		std::ofstream out(m_fileName);
		if (out)
		{
			int numTstPatients = 0;
			int numTrgPatients = 0;
			std::cout << "Saving lineup..." << std::endl;
			m_testWaitTime.write(out);
			out << ",";
			m_triageWaitTime.write(out);
			out << "\n";
			for (int i = 0; i < m_numPatients; i++)
			{
				m_patientLineup[i]->write(out);
				out << '\n';
				if (m_patientLineup[i]->type() == 'C')
				{
					numTstPatients++;
				}
				else
				{
					numTrgPatients++;
				}
			}
			std::cout << numTstPatients << " Contagion Tests and " 
				<< numTrgPatients << " Triage records were saved!" << std::endl;
		}
	}

	void PreTriage::registerPatient() {}

	void PreTriage::admit() {}

	void PreTriage::displayLineupTable(char type) const
	{
		if (m_numPatients == 0)
		{
			std::clog << "Line up is empty!\n";
		}
		else
		{
			std::cout << "Row - Patient name                                          OHIP     Tk #  Time" << std::endl;
			std::cout << "-------------------------------------------------------------------------------" << std::endl;
			int counter = 0;
			for (int i = 0; i < m_numPatients; i++)
			{
				if (m_patientLineup[i]->type() == type)
				{
					counter++;
					std::clog.width(4);
					std::clog.setf(std::ios::left);
					std::clog << counter;
					std::clog.unsetf(std::ios::left);
					std::clog << "- ";
					m_patientLineup[i]->write(std::clog);
					std::clog << "\n";
				}
			}
		}
		std::cout << "-------------------------------------------------------------------------------" << std::endl;
	}

	void PreTriage::lineup() const 
	{
		Menu subMenu("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
		int selection;
		switch (subMenu >> selection) {
		case 1:
			displayLineupTable('C');
			break;
		case 2:
			displayLineupTable('T');
			break;
		case 0:
			break;
		}
	}

	PreTriage::~PreTriage()
	{
		save();
		for (int i = 0; i < MAX_PATIENTS; i++)
		{
			delete m_patientLineup[i];
		}
		m_numPatients = 0;
		delete[] m_fileName;
	}

	void PreTriage::run()
	{
		Menu mainMenu("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup");
		int selection;
		while (mainMenu >> selection) {
			switch (selection) {
			case 1: 
				registerPatient();
				break;
			case 2:
				admit();
				break;
			case 3:
				lineup();
				break;
			default:
				break;
			}
		}
	}
}
