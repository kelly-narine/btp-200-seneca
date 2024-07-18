/* Citation and Sources...
Final Project Milestone 5, Part 4
Module: TestPatient
Filename: TestPatient.cpp
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/03/31  Preliminary release
-----------------------------------------------------------
*/

#include "TestPatient.h"
namespace seneca
{
	/// <summary>
	/// Global variable to determine the next Ticket number
	/// </summary>
	int g_nextTestTicket = 1;

	TestPatient::TestPatient() : Patient(g_nextTestTicket++) { }

	char TestPatient::type() const
	{
		return 'C';
	}

	std::ostream& TestPatient::write(std::ostream& ostr) const
	{
		if (&ostr == &std::cout)
		{
			ostr << "Contagion TEST" << std::endl;
		}
		Patient::write(ostr);
		return ostr;
	}

	std::istream& TestPatient::read(std::istream& istr)
	{
		
		Patient::read(istr);
		if (&istr != &std::cin)
		{
			g_nextTestTicket = Patient::number() + 1;
		}
		return istr;
	}
}
