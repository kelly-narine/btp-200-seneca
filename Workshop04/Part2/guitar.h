#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>
#include "guitarString.h"


namespace seneca
{
	/// <summary>
	/// Class containing information about a Guitar
	/// </summary>
	class Guitar
	{
		/// <summary>
		/// Statically-allocated char array containing name of Guitar model
		/// </summary>
		char m_model[65];

		/// <summary>
		/// Dynamically-allocated array containing Guitar's GuitarStrings
		/// </summary>
		GuitarString* m_strings;

		/// <summary>
		/// Number of GuitarStrings in a Guitar
		/// </summary>
		int m_cntStrings;

	public:
		/// <summary>
		/// Default Guitar Constructor (Special Member Function)
		/// </summary>
		/// <param name="model"> Guitar model name. By default it's "Stratocaster" </param>
		Guitar(const char* model = "Stratocaster");

		/// <summary>
		/// Custom Parameterized Guitar Constructor (Special Member Function)
		/// </summary>
		/// <param name="strings"> Address of array of type GuitarString </param>
		/// <param name="cntStrings"> Number of GuitarStrings in array of type GuitarString </param>
		/// <param name="model"> Guitar model name </param>
		Guitar(const GuitarString* strings, int cntStrings, const char* model);
		
		/// <summary>
		/// Modifier that removes all the GuitarStrings from the current object, 
		/// and replaces them with those received as parameter
		/// </summary>
		/// <param name="strings"> Address of array of type GuitarString </param>
		/// <param name="cntStrings"> Number of GuitarStrings in array of type GuitarString </param>
		/// <returns> Reference to the current object of type Guitar </returns>
		Guitar& reString(const GuitarString* strings, int cntStrings);
		
		/// <summary>
		/// Modifier that changes a single object of type GuitarString with the one received as parameter
		/// </summary>
		/// <param name="aString"> Reference to a single object of type GuitarString </param>
		/// <param name="idx"> Index of the GuitarString 
		/// from array of object of type GuitarString to modify </param>
		/// <returns> Reference to the current object of type Guitar </returns>
		Guitar& reString(const GuitarString &aString, int idx);
		
		/// <summary>
		/// Modifier that removes all the GuitarString objects from the current object of type Guitar
		/// </summary>
		/// <returns> Reference to the current object of type Guitar </returns>
		Guitar& deString();

		/// <summary>
		/// Query that returns true if the guitar has at least one string, false otherwise
		/// </summary>
		/// <returns> true if the guitar has at least one string, false otherwise </returns>
		bool isStrung() const;

		/// <summary>
		/// Query that inserts into the parameter the content of the current Guitar instance
		/// </summary>
		/// <param name="out"> Reference to an object of type std::ostream. 
		/// By default, this parameter is std::cout </param>
		/// <returns> Reference to the object of type std::ostream received as parameter </returns>
		std::ostream& display(std::ostream& out = std::cout) const;

		/// <summary>
		/// Guitar Destructor (Special Member Function)
		/// </summary>
		~Guitar();
	};
}

#endif
