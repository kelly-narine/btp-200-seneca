#include <fstream>
#include <iostream>
#include "inbox.h"
namespace seneca
{
	Inbox::Inbox()
	{
		m_emails = nullptr;
		m_cntEmails = 0;
	}

	Inbox::Inbox(const Inbox& inbox)
	{
		m_emails = nullptr; // Ensure value of resource variable is safe by initializing it
		*this = inbox;
	}

	Inbox& Inbox::operator = (const Inbox& inbox)
	{
		if (this != &inbox)
		{
			delete[] m_emails;
			// Shallow Copy
			m_cntEmails = inbox.m_cntEmails;

			// Deep Copy
			if (inbox.m_emails != nullptr)
			{
				m_emails = new Email[m_cntEmails];
				for (int i = 0; i < m_cntEmails; i++)
				{
					m_emails[i] = inbox.m_emails[i];
				}
			}
			else
			{
				m_emails = nullptr;
			}
		}

		return *this;
	}

	Inbox::~Inbox()
	{
		delete[] m_emails;
		m_emails = nullptr;
		m_cntEmails = 0;
	}

	Inbox& Inbox::operator += (const Email& email)
	{
		Email* tempEmails = new Email[m_cntEmails + 1];
		for (int i = 0; i < m_cntEmails; i++)
		{
			tempEmails[i] = m_emails[i];
		}
		tempEmails[m_cntEmails] = email;

		delete[] m_emails;
		m_emails = tempEmails;
		m_cntEmails++;
		return *this;
	}

	Inbox Inbox::operator + (const Email& email) const
	{
		Inbox inbox = Inbox(*this);
		inbox += email;
		return inbox;
	}

	void Inbox::load(const char* fileName)
	{
		if (fileName[0] != '\0')
		{
			std::ifstream fin;
			fin.open(fileName);
			if (fin.is_open())
			{
				// Method 1 - adding email to inbox
				bool isEmpty = false;
				while (!isEmpty)
				{
					Email email;
					if (email.load(fin))
					{
						*this += email;
					}
					else
					{
						isEmpty = true;
					}	
				}
				// Method 2 - adding email to inbox
				/*
				while (fin)
				{
					Email email;
					email.load(fin);
					*this += email;
				}
				*/
				fin.close();
			}
			else
			{
				std::cout << "File did not open successfully" << std::endl;
			}
		}
	}

	void Inbox::save(const char* fileName) const
	{
		if (fileName[0] != '\0')
		{
			std::ofstream fout;
			fout.open(fileName);
			if (fout.is_open())
			{
				for (int i = 0; i < m_cntEmails; i++)
				{
					fout << m_emails[i];
				}
				fout.close();
			}
			else
			{
				std::cout << "File did not open successfully" << std::endl;
			}
		}
	}

	std::ostream& operator << (std::ostream& out, const Inbox& inbox)
	{
		for (int i = 0; i < inbox.m_cntEmails; i++)
		{
			out << inbox.m_emails[i];
		}
		return out;
	}
}
