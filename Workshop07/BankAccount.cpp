#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "BankAccount.h"
namespace seneca
{
	double BankAccount::getBalance() const
	{
		return m_balance;
	}

	void BankAccount::setBalance(double newBalance)
	{
		m_balance = newBalance;
	}

	void BankAccount::writeCurrency(std::ostream& out, double amount) const
	{
		out << "$";
		out.setf(std::ios::fixed);
		out.precision(2);
		out << amount;
		out.unsetf(std::ios::fixed);
	}

	BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)
	{
		std::strcpy(m_name, name);
		m_openDate = openDate;
		m_depInfo = depInfo;
		m_balance = balance;
	}

	std::ostream& BankAccount::write(std::ostream& out) const
	{
		out << ">> ";
		out << m_name;
		out << " | ";
		writeCurrency(out, m_balance);
		out << " | ";
		out << m_openDate;
		out << " | ";
		out << m_depInfo;
		return out;
	}

	std::istream& BankAccount::read(std::istream& in)
	{
		std::cout << "Name: ";
		in.getline(m_name, 100, '\n');
		std::cout << "Opening Balance: ";
		in >> m_balance;
		std::cout << "Date Opened ";
		in >> m_openDate;
		in >> m_depInfo;
		return in;
	}

	std::ostream& operator << (std::ostream& out, const BankAccount& account)
	{
		account.write(out);
		return out;
	}

	std::istream& operator >> (std::istream& in, BankAccount& account)
	{
		account.read(in);
		return in;
	}
}
