#include "SavingsAccount.h"
#include "BankAccount.h"
namespace seneca
{
	void SavingsAccount::writeInterest(std::ostream& out) const
	{
		out.setf(std::ios::fixed);
		out.precision(3);
		out << m_interest;
		out.unsetf(std::ios::fixed);
		out << "%";
	}

	SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, 
		double balance, double interest, Date interestDate): BankAccount(name, openDate, depInfo, balance) // Constructs BankAccount then SavingsAccount
	{
		m_interest = interest;
		m_interestDate = interestDate;
	}

	void SavingsAccount::applyInterest(const Date& today)
	{
		double originalBalance = BankAccount::getBalance();
		double interest = originalBalance * m_interest;
		double newBalance = originalBalance + interest;
		BankAccount::setBalance(newBalance);
		Date originalInterestDate = m_interestDate;
		Date newInterestDate = today;

		std::cout << "   ";
		BankAccount::writeCurrency(std::cout, originalBalance);
		std::cout << " + ";
		BankAccount::writeCurrency(std::cout, interest);
		std::cout << " (";
		writeInterest(std::cout);
		std::cout << ") = ";
		BankAccount::writeCurrency(std::cout, newBalance);
		std::cout << " | ";
		std::cout << originalInterestDate;
		std::cout << " => ";
		std::cout << newInterestDate;
		std::cout << std::endl;
		m_interestDate = newInterestDate;
	}

	std::ostream& SavingsAccount::write(std::ostream& out) const
	{
		BankAccount::write(out); // shadowing
		out << " | ";
		writeInterest(out);
		out << " | ";
		out << m_interestDate;
		return out;
	}

	std::istream& SavingsAccount::read(std::istream& in)
	{
		BankAccount::read(in); // shadowing
		std::cout << "Interest Date ";
		in >> m_interestDate;
		std::cout << "Interest Rate: ";
		in >> m_interest;
		return in;
	}

	std::istream& operator >> (std::istream& in, SavingsAccount& account)
	{
		account.read(in);
		return in;
	}
	std::ostream& operator << (std::ostream& out, const SavingsAccount& account)
	{
		account.write(out);
		return out;
	}
}
