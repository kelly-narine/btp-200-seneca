#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include "LibraryItem.h"
namespace seneca
{
	/// <summary>
	/// Class containing information on Book (Derived from LibraryItem)
	/// </summary>
	class Book: public LibraryItem
	{
		char* m_author; // resource to manage

	public:
		/// <summary>
		/// Book parameterized Constructor (Special Member Fucntion)
		/// </summary>
		/// <param name="title"> title of Book </param>
		/// <param name="year"> publication year of the Book </param>
		/// <param name="author"> name of the author of the Book </param>
		Book(const char* title, int year, const char* author);

		/// <summary>
		/// Book Copy-Constructor (part of Rule-of-Three)
		/// </summary>
		/// <param name="item"> Unmodifiable reference to object of type Book </param>
		Book(const Book&);

		/// <summary>
		/// Book Copy-Assignment Operator (part of Rule-of-Three)
		/// </summary>
		/// <param name="item"> Unmodifiable reference to object of type Book </param>
		/// <returns></returns>
		Book& operator = (const Book&);

		/// <summary>
		/// Book Destructor (Special Member Function and Part of Rule-of-Three)
		/// </summary>
		~Book();

		/// <summary>
		/// Virtual Function that outputs information on Book
		/// </summary>
		/// <param name="ostr"> Reference to output stream object (std::cout by default) </param>
		/// <returns> Reference to output stream object </returns>
		virtual std::ostream& display(std::ostream& ostr = std::cout) const;

		/// <summary>
		/// Checks for non-null author names and checks to see if the current object's author name 
		/// is lexicographically greater than the other object's author name specified in the parameter
		/// </summary>
		/// <param name="other"> Unmodifiable reference to object of type Book </param>
		/// <returns> true if current object's name is lexicographically greater than the one, false otherwise </returns>
		bool operator > (const Book& other) const;
	};
}
#endif
