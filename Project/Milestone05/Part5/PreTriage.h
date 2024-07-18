/* Citation and Sources...
Final Project Milestone 5, Part 5
Module: PreTriage
Filename: PreTriage.h
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/04/03  Added override keyword to type function
2024/03/31  Preliminary release
-----------------------------------------------------------
*/

#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H
#include "Time.h"
#include "Patient.h"
namespace seneca
{
	const int MAX_PATIENTS = 100;

	class PreTriage
	{
		Time m_testWaitTime;
		Time m_triageWaitTime;
		Patient* m_patientLineup[MAX_PATIENTS];
		char* m_fileName;
		int m_numPatients;
		Time getWaitTime(const Patient&) const;
		void setAverageWaitTime(Patient&);
		int indexOfFirstInLine(char type) const;
		void load();
		void save() const;
		void registerPatient();
		void admit();
		void lineup() const;
		void getAndSetRegistrationInfo(char type);
		void callPatient(char type);
		void displayLineupTable(char type) const;

	public:
		PreTriage(const char* fileName);
		~PreTriage();
		void run();
	};
}
#endif
