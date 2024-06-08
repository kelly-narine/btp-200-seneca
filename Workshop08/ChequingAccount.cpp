#include <iostream>
#include "ChequingAccount.h"

namespace seneca
{

	ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee): Account(balance)
	{
		m_transactionFee = 0.0;
		m_monthlyFee = 0.0;
		if (transactionFee > 0)
		{
			m_transactionFee = transactionFee;
		}
		if (monthlyFee > 0)
		{
			m_monthlyFee = monthlyFee;
		}
	}

	bool ChequingAccount::credit(double amount)
	{
		bool creditSuccess = Account::credit(amount);
		bool debitSuccess = false;
		if (creditSuccess)
		{
			Account::debit(m_transactionFee);
		}
		return debitSuccess;
	}

	bool ChequingAccount::debit(double amount)
	{
		bool debit1Success = Account::debit(amount);
		bool debit2Success = false;
		if (debit1Success)
		{
			debit2Success = Account::debit(m_transactionFee);
		}
		return debit2Success;
	}

	void ChequingAccount::monthEnd()
	{
		Account::debit(m_monthlyFee);
	}

	void ChequingAccount::display(std::ostream& out) const
	{
		out << "Account type: Chequing" << std::endl;
		out << "Balance: $";
		out.setf(std::ios::fixed);
		out.precision(2);
		out << balance();
		out.unsetf(std::ios::fixed);
		out << std::endl;
		out << "Per Transaction Fee: ";
		out.setf(std::ios::fixed);
		out.precision(2);
		out << m_transactionFee;
		out.unsetf(std::ios::fixed);
		out << std::endl;
		out << "Monthly Fee: ";
		out.setf(std::ios::fixed);
		out.precision(2);
		out << m_monthlyFee;
		out.unsetf(std::ios::fixed);
		out << std::endl;
	}
}
