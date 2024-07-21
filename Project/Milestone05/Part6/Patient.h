/* Citation and Sources...
Final Project Milestone 5, Part 6
Module: Patient
Filename: Patient.h
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/03/31  Added back virtual keyword and added override keyword on read and write function
2024/03/30  Added comment on Patient class and removed virtual from read and write function
2024/03/27  Preliminary release
-----------------------------------------------------------
*/

#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H
#include "Ticket.h"
namespace seneca
{
	/// <summary>
	/// Class containing information on Patient (Derived from IOAble)
	/// </summary>
	class Patient : public IOAble
	{
		char* m_name;
		int m_ohipNumber;
		Ticket m_ticket;

	public:
		/// <summary>
		/// Parameterized Patient Constructor (Special Member Function)
		/// </summary>
		/// <param name="ticketNum"> ticket number </param>
		Patient(int ticketNum);

		/// <summary>
		/// Patient Copy-Constructor (part of Rule-of-Three)
		/// </summary>
		/// <param name="patient"> Unmodifiable reference to object of type Patient </param>
		Patient(const Patient&);

		/// <summary>
		/// Patient Copy-Assignment Operator (part of Rule-of-Three)
		/// </summary>
		/// <param name="patient"> Unmodifiable reference to object of type Patient </param>
		/// <returns> Reference to the current object of type Patient </returns>
		Patient& operator=(const Patient&);

		/// <summary>
		/// Patient Destructor
		/// </summary>
		~Patient();

		/// <summary>
		/// Pure virtual overloaded char conversion operator that 
		/// returns a single character that identifies the type of the Patient
		/// </summary>
		/// <returns> a single character that identifies the type of the Patient </returns>
		virtual char type() const = 0;

		/// <summary>
		/// Overloaded == operator that compares the current Patient object 
		/// with a single character specified in the parameter
		/// </summary>
		/// <param name="type"> Patient Type character </param>
		/// <returns> true if the values returned by the type function of this patient 
		/// and the provided single character are identical, false otherwise </returns>
		bool operator==(char type) const;

		/// <summary>
		/// Overloaded == operator that compares the current Patient object to
		/// Patient object specified in the parameter
		/// </summary>
		/// <param name="patient"> Unmodifiable reference to object of type Patient </param>
		/// <returns> true if the type of the current Patient object is the same as the type 
		/// of the Patient object specified in the parameter, otherwise return false </returns>
		bool operator==(const Patient&) const;

		/// <summary>
		/// Sets the time of the patient's ticket to the current time (Modifier)
		/// </summary>
		void setArrivalTime();

		/// <summary>
		/// Retrieve the Time of the patient's ticket (Query)
		/// </summary>
		/// <returns> object of type Time containing Time of the patient's ticket </returns>
		Time time() const;

		/// <summary>
		/// Retrieve number associated with the patient's ticket (Query)
		/// </summary>
		/// <returns> number associated with the patient's ticket </returns>
		int number() const;

		/// <summary>
		/// Overloaded Boolean Coversion operator that 
		/// returns true if the Patient is in a valid state, otherwise returns false
		/// </summary>
		operator bool() const;

		/// <summary>
		/// Overloaded const char* converstion operator that returns the address of the patient's name
		/// </summary>
		operator const char* () const;

		/// <summary>
		/// Virtual function that outputs information on Patient (Query)
		/// </summary>
		/// <param name="ostr"> reference to output stream object (std::cout by default) </param>
		/// <returns> reference to output stream object </returns>
		virtual std::ostream& write(std::ostream& ostr = std::cout) const override;

		/// <summary>
		/// Virtual function that extracts information on Patient from istream object (Modifier)
		/// </summary>
		/// <param name="istr"> reference to istream object (std::cin by default) </param>
		/// <returns> reference to istream object </returns>
		virtual std::istream& read(std::istream& istr = std::cin) override;
	};
}
#endif
