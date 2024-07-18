/* Citation and Sources...
Final Project Milestone 5, Part 5
Module: TriagePatient
Filename: TriagePatient.h
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/04/03  Added override keyword to type function
2024/03/31  Preliminary release
-----------------------------------------------------------
*/

#ifndef SENECA_TRIAGEPATIENT_H
#define SENECA_TRIAGEPATIENT_H
#include "Patient.h"
namespace seneca
{
	/// <summary>
	/// Class containing information on TriagePatient (derived from Patient)
	/// </summary>
	class TriagePatient : public Patient
	{
		char* m_symptoms;

	public:
		/// <summary>
		/// Default TriagePatient Constructor (Special Member Function)
		/// </summary>
		TriagePatient();

		/// <summary>
		/// Virtual function that returns a 'T' to identify TriagePatient type
		/// </summary>
		/// <returns> 'T' </returns>
		virtual char type() const override;

		/// <summary>
		/// Function that outputs information on TriagePatient
		/// </summary>
		/// <param name="ostr"> reference to output stream object (std::cout by default) </param>
		/// <returns> reference to output stream object </returns>
		std::ostream& write(std::ostream& ostr = std::cout) const override;

		/// <summary>
		/// Function that extracts information on TriagePatient from istream object
		/// </summary>
		/// <param name="istr"> reference to istream object (std::cin by default) </param>
		/// <returns> reference to istream object </returns>
		std::istream& read(std::istream& istr = std::cin) override;

		/// <summary>
		/// TriagePatient Copy-Constructor (Part of Rule-of-Three)
		/// </summary>
		/// <param name="trgP"> Un-modifiable reference to object of type TriagePatient </param>
		TriagePatient(const TriagePatient& trgP);

		/// <summary>
		/// TriagePatient Copy-Assignment Operator (Part of Rule-of-Three)
		/// </summary>
		/// <param name="trgP"> Un-modifiable reference to object of type TriagePatient </param>
		/// <returns></returns>
		TriagePatient& operator=(const TriagePatient& trgP);

		/// <summary>
		/// TriagePatient Destructor (Part of Rule-of-Three)
		/// </summary>
		~TriagePatient();
	};
}
#endif
