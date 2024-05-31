#ifndef SENECA_ABILITY_H
#define SENECA_ABILITY_H

namespace seneca
{
	/// <summary>
	/// Class containing information on a Hero's ability
	/// </summary>
	class Ability
	{
		/// <summary>
		/// Statically allocated char array that contains name of Ability
		/// </summary>
		char m_name[100];
		
		/// <summary>
		/// Strength of the Ability
		/// </summary>
		int m_strength;

	public:
		/// <summary>
		/// Default Ability Constructor (Special Member Function)
		/// </summary>
		Ability();
		
		/// <summary>
		/// Custom Ability Constructor (Special Member Function)
		/// </summary>
		/// <param name="name"> Name of Ability </param>
		/// <param name="strength"> Strength of Ability </param>
		Ability(const char* name, int strength);

		/// <summary>
		/// Obtains Ability Strength (Query)
		/// </summary>
		/// <returns> Strength of Ability </returns>
		int getStrength() const;

		/// <summary>
		/// Obtains Ability Name (Query)
		/// </summary>
		/// <returns> Name of Ability </returns>
		const char* getAbilityName() const;
	};
}
#endif
