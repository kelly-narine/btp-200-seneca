/* Citation and Sources...
Final Project Milestone 5, Part 5
Module: Menu
Filename: Menu.cpp
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/03/13  Preliminary release
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <sstream> // contains istringstream
#include "Menu.h"
namespace seneca
{
	Menu::Menu(const char* menuContent, int numberOfTabs)
	{
		m_text = nullptr;
		bool isEmpty = false;
		int size = 0;
		int options = 0;

		while (!isEmpty)
		{
			if (menuContent[size] != '\0')
			{
				if (menuContent[size] == '\n')
				{
					options++;
				}
				size++;
			}
			else
			{
				isEmpty = true;
			}
		}
		m_numOptions = options;
		m_numTabs = numberOfTabs;
		char* content = new char[size + 1]{};
		std::strcpy(content, menuContent);
		m_text = content;
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	std::ostream& Menu::indent(std::ostream& ostr) const
	{
		for (int i = 0; i < m_numTabs; i++)
		{
			ostr << "   ";
		}
		return ostr;
	}

	std::ostream& Menu::display(std::ostream& ostr) const
	{
		// read menu text line by line
		std::istringstream menuText;
		menuText.str(m_text);
		for (std::string line; std::getline(menuText, line);)
		{
			indent();
			ostr << line << std::endl;
		}
		indent();
		ostr << "0- Exit" << std::endl;
		indent();
		ostr << "> ";
		return ostr; 
	}

	int& Menu::operator>>(int& Selection)
	{
		bool done = true;
		display();

		do {			
			std::cin >> Selection;
			bool isValid = (Selection >= 0 && Selection <= m_numOptions);

			if (std::cin.fail()) 
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				done = false;
				std::cout << "Bad integer value, try again: ";
			}
			else if (std::cin.peek() != '\n') 
			{
				done = false;
				std::cout << "Only enter an integer, try again: ";
				std::cin.ignore();
			}
			else if (!isValid)
			{
				done = false;
				std::cout << "Invalid value enterd, retry[0 <= value <= " << m_numOptions << "]: ";
				std::cin.ignore();
			}
			else
			{
				done = true;
			}
		} while (!done);
		
		return Selection;
	}
}
