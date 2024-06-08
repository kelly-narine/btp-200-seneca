#include "Account.h"
namespace seneca
{
	Account::Account(double balance)
	{
		if (balance < 0)
		{
			m_balance = 0.0;
		}
		else
		{
			m_balance = balance;
		}
	}

	bool Account::credit(double amount)
	{
		bool success = false;
		if (amount > 0)
		{
			m_balance += amount;
			success = true;
		}
		return success;
	}

	bool Account::debit(double amount)
	{
		bool success = false;
		if (amount > 0)
		{
			m_balance -= amount;
			success = true;
		}
		return success;
	}

	double Account::balance() const
	{
		return m_balance;
	}
}
