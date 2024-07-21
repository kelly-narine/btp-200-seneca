/* Citation and Sources...
Final Project Milestone 5, Part 6
Module: IOAble
Filename: IOAble.h
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/03/31  Preliminary release
-----------------------------------------------------------
*/

#include <iostream>
namespace seneca
{
	/// <summary>
	/// IOAble Interface 
	/// </summary>
	class IOAble
	{
	public:
		/// <summary>
		/// Pure Virtual Function for future ostream outputs
		/// </summary>
		/// <param name="out"> Reference to ouput stream object </param>
		/// <returns> Reference to ouput stream object </returns>
		virtual std::ostream& write(std::ostream&) const = 0;

		/// <summary>
		/// Pure Virtual Function for future istream inputs
		/// </summary>
		/// <param name="in"> Reference to input stream object </param>
		/// <returns> Reference to input stream object </returns>
		virtual std::istream& read(std::istream&) = 0;

		/// <summary>
		/// IOAble Interface Destructor
		/// </summary>
		virtual ~IOAble();
	};

	/// <summary>
	/// Overloaded >> operator insert the information of an IOAble object specified in second parameter
	/// into istream object specified in first parameter
	/// </summary>
	/// <param name="in"> Reference to input stream object </param>
	/// <param name="ioAble"> Reference to IOAble object </param>
	/// <returns> Reference to input stream object </returns>
	std::istream& operator >> (std::istream&, IOAble&);

	/// <summary>
	/// Overloaded << operator extract information from un-modifiable IOAble object specified in second
	/// parameter into ostream object specified in first parameter
	/// </summary>
	/// <param name="out"> Reference to output stream object </param>
	/// <param name="ioAble"> Reference to IOAble object </param>
	/// <returns> Reference to output stream object </returns>
	std::ostream& operator << (std::ostream&, const IOAble&);
}
