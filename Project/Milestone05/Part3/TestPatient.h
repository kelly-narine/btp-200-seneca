/* Citation and Sources...
Final Project Milestone 5, Part 3
Module: TestPatient
Filename: TestPatient.h
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/04/03  Added override keyword to type function
2024/03/31  Preliminary release
-----------------------------------------------------------
*/

#ifndef SENECA_TESTPATIENT_H
#define SENECA_TESTPATIENT_H
#include "Patient.h"
namespace seneca
{
	/// <summary>
	/// Class containing information on TestPatient (derived from Patient)
	/// </summary>
	class TestPatient : public Patient
	{
	public:
		/// <summary>
		/// Default TestPatient Constructor (Special Member Function)
		/// </summary>
		TestPatient();

		/// <summary>
		/// Virtual function that returns a 'C' to identify TestPatient type
		/// </summary>
		/// <returns> 'C' </returns>
		virtual char type() const override;

		/// <summary>
		/// Function that outputs information on TestPatient
		/// </summary>
		/// <param name="ostr"> reference to output stream object (std::cout by default) </param>
		/// <returns> reference to output stream object </returns>
		std::ostream& write(std::ostream& ostr = std::cout) const override;

		/// <summary>
		/// Function that extracts information on TestPatient from istream object
		/// </summary>
		/// <param name="istr"> reference to istream object (std::cin by default) </param>
		/// <returns> reference to istream object </returns>
		std::istream& read(std::istream& istr = std::cin) override;
		
		/// <summary>
		/// TestPatient Destructor
		/// </summary>
		~TestPatient() = default;
	};
}
#endif 
