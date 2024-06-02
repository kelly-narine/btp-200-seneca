#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "email.h"

namespace seneca
{
	Email::Email()
	{
		m_fromName[0] = '\0';
		m_fromAddress[0] = '\0';
		m_dateReceived[0] = '\0';
		m_subject = nullptr;
	}

	Email::Email(const Email& email)
	{
		m_subject = nullptr; // Ensure value of resource variable is safe by initializing it
		*this = email;		
	}

	Email& Email::operator = (const Email& email)
	{
		if (this != &email)
		{
			delete[] m_subject;

			// Shallow Copies
			std::strcpy(m_fromName, email.m_fromName);
			std::strcpy(m_fromAddress, email.m_fromAddress);
			std::strcpy(m_dateReceived, email.m_dateReceived);

			// Deep Copy
			if (email.m_subject != nullptr)
			{
				int counter = 0;
				while (email.m_subject[counter] != '\0')
				{
					counter++;
				}

				m_subject = new char[counter + 1];
				std::strcpy(m_subject, email.m_subject);
			}
			else
			{
				m_subject = nullptr;
			}
		}

		return *this;
	}

	Email::~Email()
	{
		delete[] m_subject;
		m_subject = nullptr;
		m_fromName[0] = '\0';
		m_fromAddress[0] = '\0';
		m_dateReceived[0] = '\0';
	}

	bool Email::load(std::istream& in)
	{
		char buffer[1000] = {};
		in.getline(m_fromAddress, 100, ',');
		in.getline(m_fromName, 100, ',');
		in.getline(buffer, 1000, ',');
		in.getline(m_dateReceived, 100, '\n');

		if (in.good())
		{
			delete[] m_subject;
			int size = 0;
			bool empty = false;
			while (!empty)
			{
				if (buffer[size] != '\0')
				{
					size++;
				}
				else
				{
					empty = true;
				}
			}
			m_subject = new char[size + 1]{};
			std::strcpy(m_subject, buffer);
			return true;
		}
		else
		{
			*this = Email();
			return false;
		}
	}

	void outputEmails(std::ostream& out, const Email& email) 
	{
		out.width(20);
		out << email.m_fromName;
		out << "  ";
		out.width(40);
		out.setf(std::ios::left);
		out << email.m_fromAddress;
		out.unsetf(std::ios::left);
		out << "  ";
		out.width(15);
		char time[8 + 1] = {};
		int j = 0;
		for (int i = 11; i < 19; i++)
		{
			time[j] = email.m_dateReceived[i];
			j++;
		}
		out.setf(std::ios::left);
		out << time;
		out.unsetf(std::ios::left);
		out << "  ";
		out << email.m_subject << std::endl;
	}

	std::ostream& operator<<(std::ostream& out, const Email& email)
	{
		bool isEmpty = (email.m_fromName[0] == '\0' && email.m_fromAddress[0] == '\0' && email.m_dateReceived[0] == '\0' && email.m_subject == nullptr);
		if (!isEmpty)
		{			
			outputEmails(out, email);
		}
		return out;
	}

}
