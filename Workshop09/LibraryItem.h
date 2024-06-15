#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H
#include <iostream>
namespace seneca
{
	/// <summary>
	/// Class containing information on LibraryItem
	/// </summary>
	class LibraryItem
	{
		char* m_title; // resource to manage
		int m_year;

	public:
		/// <summary>
		/// Default LibraryItem constructor (Special Member Function)
		/// </summary>
		LibraryItem();

		/// <summary>
		/// Parameterized LibraryItem constructor (Special Member Function)
		/// </summary>
		/// <param name="title"> title of LibraryItem </param>
		/// <param name="year"> publication year of the item </param>
		LibraryItem(const char* title, int year);

		/// <summary>
		/// LibraryItem Copy-Constructor (part of Rule-of-Three)
		/// </summary>
		/// <param name="item"> Unmodifiable reference to object of type LibraryItem </param>
		LibraryItem(const LibraryItem&);

		/// <summary>
		/// LibraryItem Copy-Assignment Operator (part of Rule-of-Three)
		/// </summary>
		/// <param name="item"> Unmodifiable reference to object of type LibraryItem </param>
		/// <returns></returns>
		LibraryItem& operator = (const LibraryItem&);

		/// <summary>
		/// LibraryItem Destructor (Special Member Function and Part of Rule-of-Three)
		/// </summary>
		virtual ~LibraryItem();

		/// <summary>
		/// Virtual Function that outputs information on LibraryItem
		/// </summary>
		/// <param name="ostr"> Reference to output stream object (std::cout by default) </param>
		/// <returns> Reference to output stream object </returns>
		virtual std::ostream& display(std::ostream& ostr = std::cout) const; // override
	};
}
#endif 

