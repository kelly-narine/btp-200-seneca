/* Citation and Sources...
Final Project Milestone 5, Part 4
Module: Time
Filename: Time.h
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/03/31  Preliminary release
-----------------------------------------------------------
*/

#ifndef SENECA_TIME_H
#define SENECA_TIME_H
#include <iostream>
namespace seneca
{
	/// <summary>
	/// Class that contains information about Time
	/// </summary>
	class Time
	{
		/// <summary>
		/// Number of minutes in Time
		/// </summary>
		int m_minutes;

	public:
		/// <summary>
		/// Time constructor that initializes object of type Time (Special Member Function)
		/// </summary>
		/// <param name="min"></param>
		Time(unsigned int min = 0u);

		/// <summary>
		/// Resets time to the current time (Modifier)
		/// </summary>
		/// <returns> Reference to the current Time object </returns>
		Time& reset();

		/// <summary>
		/// Writes the time in HH::MM format (Query)
		/// </summary>
		/// <param name="ostr"> Reference to output stream object. std::cout by default </param>
		/// <returns> Reference to output stream object </returns>
		std::ostream& write(std::ostream& ostr = std::cout) const;

		/// <summary>
		/// Reads time from istream in HH:MM format (Modifier)
		/// </summary>
		/// <param name="istr"> Reference to input stream object. std::cin by default </param>
		/// <returns> Reference to input stream object </returns>
		std::istream& read(std::istream& istr = std::cin);

		/// <summary>
		/// Overloaded cast-to-unsigned int operator. Returns the number of minutes in Time.
		/// </summary>
		operator unsigned int() const;

		/// <summary>
		/// Overloaded *= operator multiplies the number of minutes in Time 
		/// multiplied by value specified in the parameter.
		/// </summary>
		/// <param name="val"> number to multiply minutes by </param>
		/// <returns> Reference to current Time object </returns>
		Time& operator*= (int val);

		/// <summary>
		/// Overloaded -= operator calculates the difference between the current Time object and 
		/// Time object reference passed in the parameter
		/// </summary>
		/// <param name="D"> Un-modifiable reference to object of type Time </param>
		/// <returns> Reference to current Time object </returns>
		Time& operator-= (const Time& D);

		/// <summary>
		/// Overloaded - operator calculates the difference between the current Time object and 
		/// Time object reference passed in the parameter with no side effects (does not actually modify
		/// the current Time object
		/// </summary>
		/// <param name="T"> Un-modifiable reference to object of type Time </param>
		/// <returns> Object of type Time </returns>
		Time operator-(const Time& T) const;
	}; 

	/// <summary>
	/// Free Helper Function that reads time in HH:MM format 
	/// on Time object reference specified in parameter
	/// </summary>
	/// <param name="istr"> Reference to input stream object </param>
	/// <param name="time"> Reference to object of type Time </param>
	/// <returns> Reference to input stream object </returns>
	std::istream& operator>>(std::istream&, Time&);

	/// <summary>
	/// Free Helper Function that writes time in HH:MM format on Time object reference 
	/// specified in parameter
	/// </summary>
	/// <param name="ostr"> Reference to output stream object </param>
	/// <param name="time"> Un-modifiable reference to object of type Time </param>
	/// <returns></returns>
	std::ostream& operator<<(std::ostream&, const Time&);
}
#endif
