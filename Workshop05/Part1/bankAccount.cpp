#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <cmath>
#include "bankAccount.h"

namespace seneca
{
	BankAccount::BankAccount(const char* name, bool checking)
	{
		m_balance = 0;
		m_transactions = 0;
		m_checking = checking;
		if (name == nullptr || name[0] == '\0')
		{
			m_userName[0] = '\0';
		}
		else
		{
			std::strcpy(m_userName, name);
		}
	}

	BankAccount::operator bool() const
	{
		return m_userName[0] != '\0';
	}

	BankAccount::operator double() const
	{
		if (*this)
		{
			return m_balance;
		}
		else
		{
			return std::nan("");
		}
	}

	BankAccount::operator const char* () const
	{
		if (*this)
		{
			return m_userName;
		}
		else
		{
			return "Not Open";
		}
	}

	BankAccount::operator int() const
	{
		if (*this)
		{
			return m_transactions;
		}
		else
		{
			return -1;
		}
	}

	BankAccount& BankAccount::operator += (double amount)
	{
		if (*this)
		{
			m_balance += amount;
			m_transactions++;
		}

		return *this;
	}

	BankAccount& BankAccount::operator -= (double amount)
	{
		*this += (amount * -1);
		return *this;
	}

	BankAccount& BankAccount::operator++()
	{
		bool isValid = (*this && m_balance > 0);
		if (isValid)
		{
			if (m_checking)
			{
				m_balance += (m_balance * 0.005);
			}
			else
			{
				m_balance += (m_balance * 0.025);
			}
		}
		return *this;
	}

	BankAccount BankAccount::operator++(int)
	{
		BankAccount result;
		result = *this;
		++(*this);
		return result;
	}

	bool BankAccount::operator > (double amount) const
	{
		if (*this)
		{
			if (m_balance > amount)
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

	bool operator > (double amount, const BankAccount& account)
	{
		return ((account > amount) == 0); // vice versa of the overloaded > member operator as amount goes to left of operation here, while amount went to the right of operation in member operator
	}

	BankAccount BankAccount::operator+(double amount) const
	{
		BankAccount result;
		result = *this;
		result += amount;
		return result;
	}

	void BankAccount::display() const
	{
		if (*this) // if the current BankAccount is open (called via the bool operator)
		{
			std::cout << m_userName << " -> " << "$" << m_balance << " in ";
			if (m_checking)
			{
				std::cout << "checking account." << std::endl;
			}
			else
			{
				std::cout << "saving account." << std::endl;
			}
		}
	}
}
