/* Citation and Sources...
Final Project Milestone 5, Part 2
Module: Menu
Filename: Menu.h
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/03/13  Preliminary release
-----------------------------------------------------------
*/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
namespace seneca
{
	/// <summary>
	/// Class containing information on Menu
	/// </summary>
	class Menu {
		/// <summary>
		/// Constant char pointer that contains content of menu to be displayed
		/// </summary>
		const char* m_text;

		/// <summary>
		/// Number of options in the Menu
		/// </summary>
		int m_numOptions;

		/// <summary>
		/// Number of tabs to indent the displayed Menu by
		/// </summary>
		int m_numTabs;

	public:
		/// <summary>
		/// Menu Constructor (Special Member Function)
		/// </summary>
		/// <param name="menuContent"> Content of Menu in const char* pointer </param>
		/// <param name="numberOfTabs">  Number of tabs to indent the displayed Menu by </param>
		Menu(const char* menuContent, int numberOfTabs = 0);

		/// <summary>
		/// Menu Destructor (Special Member Function)
		/// </summary>
		~Menu();

		/// <summary>
		/// probhibited Menu copy-constructor
		/// </summary>
		/// <param name="menu"> Un-modifiable reference to object of type Menu </param>
		Menu(const Menu&) = delete;  

		/// <summary>
		/// probhibited Menu copy-assignment operator
		/// </summary>
		/// <param name="menu"> Un-modifiable reference to object of type Menu </param>
		/// <returns> Reference to object of type Menu </returns>
		Menu& operator=(const Menu&) = delete; 

		/// <summary>
		/// Writes indents/tabs by number of tabs in current object of type Menu (Query)
		/// </summary>
		/// <param name="ostr"> Reference to output stream object. std::cout by default </param>
		/// <returns> Reference to output stream object </returns>
		std::ostream& indent(std::ostream& ostr = std::cout) const;
		
		/// <summary>
		/// Writes the content of current Menu object (Query)
		/// </summary>
		/// <param name="ostr"> Reference to output stream object. std::cout by default </param>
		/// <returns> Reference to output stream object </returns>
		std::ostream& display(std::ostream& ostr = std::cout) const;
		
		/// <summary>
		/// Overloaded >> operator that allows user to navigate through the Menu. User will continuously 
		/// be prompted to choose a menu option until they choose to exit the Menu. Menu navigates 
		/// according to user's selection.
		/// </summary>
		/// <param name="Selection"> User Menu option selection </param>
		/// <returns> Reference to user Menu option selection </returns>
		int& operator>>(int& Selection);
	};
}
#endif
