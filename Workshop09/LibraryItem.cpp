#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "LibraryItem.h"
namespace seneca
{
	LibraryItem::LibraryItem()
	{
		m_title = nullptr;
		m_year = 0;
	}

	LibraryItem::LibraryItem(const char* title, int year)
	{
		//if (title[0] != '\0' && year > 0)
		//{
			m_title = new char[std::strlen(title) + 1]{};
			std::strcpy(m_title, title);
			m_year = year;
		//}
	}

	LibraryItem::LibraryItem(const LibraryItem& item)
	{
		m_title = nullptr;
		*this = item;
	}

	LibraryItem& LibraryItem::operator = (const LibraryItem& item)
	{
		// check for self-assignment
		if (this != &item)
		{
			// clean-up
			delete[] m_title;

			// shallow-copy
			m_year = item.m_year;

			// deep-copy
			if (item.m_title != nullptr)
			{
				m_title = new char[std::strlen(item.m_title) + 1]{};
				std::strcpy(m_title, item.m_title);
			}
			else
			{
				m_title = nullptr;
			}
		}
		return *this;
	}

	LibraryItem::~LibraryItem()
	{
		delete[] m_title;
	}

	std::ostream& LibraryItem::display(std::ostream& ostr) const
	{
		ostr << "Title: " << m_title << " (" << m_year << ")";
		return ostr;
	}
}
