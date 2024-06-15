#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
namespace seneca
{
	Book::Book(const char* title, int year, const char* author) : LibraryItem(title, year)
	{
		m_author = new char[std::strlen(author) + 1]{};
		std::strcpy(m_author, author);
	}

	Book::Book(const Book& book) : LibraryItem(book)
	{
		m_author = nullptr;
		*this = book;
	}

	Book& Book::operator = (const Book& book)
	{
		if (this != &book)
		{
			// force copy-assignment from base type
			(LibraryItem&)*this = book;

			// clean-up
			delete[] m_author;

			// deep-copy
			if (book.m_author != nullptr)
			{
				m_author = new char[std::strlen(book.m_author) + 1]{};
				std::strcpy(m_author, book.m_author);
			}
			else
			{
				m_author = nullptr;
			}
		}
		return *this;
	}

	Book::~Book()
	{
		delete[] m_author;
	}

	std::ostream& Book::display(std::ostream& ostr) const
	{
		LibraryItem::display(ostr);
		ostr << std::endl;
		ostr << "Author: " << m_author;
		return ostr;
	}

	bool Book::operator > (const Book& other) const
	{
		if (m_author != nullptr && other.m_author != nullptr)
		{
			if (std::strcmp(m_author, other.m_author) > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}
