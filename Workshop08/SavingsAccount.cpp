#include <iostream>
#include "SavingsAccount.h"

namespace seneca
{
	SavingsAccount::SavingsAccount(double balance, double interestRate): Account(balance)
	{
		if (interestRate > 0)
		{
			m_interestRate = interestRate;
		}
		else
		{
			m_interestRate = 0.0;
		}
	}

	void SavingsAccount::monthEnd()
	{
		double interestEarned = balance() * m_interestRate;
		Account::credit(interestEarned);
	}

	void SavingsAccount::display(std::ostream& out) const
	{
		out<< "Account type: Savings" << std::endl;
		out << "Balance: $";
		out.setf(std::ios::fixed);
		out.precision(2);
		out << balance();
		out.unsetf(std::ios::fixed);
		out << std::endl;
		out << "Interest Rate (%): ";
		out.setf(std::ios::fixed);
		out.precision(2);
		out << m_interestRate * 100;
		out.unsetf(std::ios::fixed);
		out << std::endl;
	}
}
