#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "ability.h"

namespace seneca
{
	/// <summary>
	/// Class containing information on Hero
	/// </summary>
	class Hero
	{
		/// <summary>
		/// Statically-allocated char array that contains name of Hero
		/// </summary>
		char m_name[100];

		/// <summary>
		/// Dynamically-allocated array of type Ability that contains a Hero's abilities
		/// </summary>
		Ability* m_abilities;

		/// <summary>
		/// Number of Ability a hero has 
		/// </summary>
		int m_cntAbilities;

		/// <summary>
		/// Level of a Hero
		/// </summary>
		int m_level;

	public:
		/// <summary>
		/// Default Hero Constructor (Special Member Function)
		/// </summary>
		Hero();

		/// <summary>
		/// Custom Hero Constructor (Special Member Function)
		/// </summary>
		/// <param name="name"> Name of Hero </param>
		/// <param name="abilities"> Address of array of type Ability </param>
		/// <param name="cntAbilities"> Number of Ability hero has </param>
		Hero(const char* name, const Ability* abilities, int cntAbilities);

		/// <summary>
		/// Conversion-to-String Operator that returns the name of the Hero (Query)
		/// </summary>
		operator const char* () const;

		/// <summary>
		/// Conversion-to-Int Operator that returns the total strength of the Hero (Query)
		/// </summary>
		operator int() const;

		/// <summary>
		/// Overloaded += operator to add ability specified in parameter to Hero's array of type Ability 
		/// (Modifier)
		/// </summary>
		/// <param name="ability"> Reference to unmodifiable object of type Ability </param>
		/// <returns> Reference to object of type Hero </returns>
		Hero& operator += (const Ability& ability);

		/// <summary>
		/// Overloaded += operator to increase / decrease level of Hero by number specified in parameter
		/// (Modifier)
		/// </summary>
		/// <param name="lvlChange"> number of levels to increase / decrease </param>
		/// <returns> Reference to object of type Hero </returns>
		Hero& operator += (int lvlChange);

		/// <summary>
		/// Pre-fix operator that increments Hero level by one (Modifier)
		/// </summary>
		/// <returns> Reference to object of type Hero </returns>
		Hero& operator++();

		/// <summary>
		/// Ouputs content of Hero (Query)
		/// </summary>
		void display() const;
		
		/// <summary>
		/// Hero Destructor (Special Member Function)
		/// </summary>
		~Hero();
	};

	/// <summary>
	/// Overloaded < Operator that compares the total strength two Heroes (Free Helper Function)
	/// </summary>
	/// <param name="h1"> Reference to unmodifiable object of type Hero </param>
	/// <param name="h2"> Reference to unmodifiable object of type Hero </param>
	/// <returns> true if total strength of Hero in first parameter is greater than total
	/// strength of Hero in second parameter, false otherwise </returns>
	bool operator < (const Hero& h1, const Hero& h2);

	/// <summary>
	/// Overloaded > Operator that compares the total strength two Heroes (Free Helper Function)
	/// </summary>
	/// <param name="h1"> Reference to unmodifiable object of type Hero </param>
	/// <param name="h2"> Reference to unmodifiable object of type Hero </param>
	/// <returns> true if total strength of Hero in first parameter is greater than total
	/// strength of Hero in second parameter, false otherwise </returns>
	bool operator > (const Hero& h1, const Hero& h2);

	/// <summary>
	/// Adds ability specified in first parameter to Hero specified in second parameter
	/// </summary>
	/// <param name="ability"> Reference to unmodifiable object of type Ability </param>
	/// <param name="hero"> Reference to object of type Hero </param>
	void operator >> (const Ability& ability, Hero& hero);

	/// <summary>
	/// Adds ability specified in second parameter to Hero specified in first parameter
	/// </summary>
	/// <param name="hero"> Reference to object of type Hero </param>
	/// <param name="ability"> Reference to unmodifiable object of type Ability </param>
	void operator << (Hero& hero, const Ability& ability);
}
#endif
