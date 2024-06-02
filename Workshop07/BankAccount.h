#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H
#include <iostream>
#include "DepositUtility.h"
namespace seneca
{
	/// <summary>
	/// Class Containing information on BankAccount (Base Class)
	/// </summary>
	class BankAccount
	{
		/// <summary>
		/// Statically-Allocated array of characters that contains name of BankAccount owner
		/// </summary>
		char m_name[100];

		/// <summary>
		/// Date BankAccount Opened
		/// </summary>
		Date m_openDate;

		/// <summary>
		/// Deposit Information for BankAccount
		/// </summary>
		DepositInfo m_depInfo;

		/// <summary>
		/// balance in the BankAccount
		/// </summary>
		double m_balance;

	protected:
		/// <summary>
		/// Obtain the balance in the BankAccount (Query)
		/// </summary>
		/// <returns> balance of the BankAccount </returns>
		double getBalance() const;

		/// <summary>
		/// Update the BankAccount balance to value specified in the parameter (Modifier)
		/// </summary>
		/// <param name="newBalance"> New balance to update BankAccount balance to </param>
		void setBalance(double newBalance);

		/// <summary>
		/// Writes the currency amount specified in the second parameter to the output stream in 
		/// $1.20 format.(Query)
		/// </summary>
		/// <param name="out"> reference to output stream object </param>
		/// <param name="amount"> amount of currency </param>
		void writeCurrency(std::ostream& out, double amount) const;

	public:
		/// <summary>
		/// BankAccount Constructor (Special Member Function)
		/// </summary>
		/// <param name="name"> name of BankAccount owner </param>
		/// <param name="openDate"> Date BankAccount Opened </param>
		/// <param name="depInfo"> Deposit Information for BankAccount </param>
		/// <param name="balance"> balance in the BankAccount </param>
		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);

		/// <summary>
		/// Write information on the current BankAccount object to the output object
		/// </summary>
		/// <param name="out"> reference to output stream object </param>
		/// <returns> reference to output stream object </returns>
		std::ostream& write(std::ostream& out) const;

		/// <summary>
		/// Read information entered for BankAccount from input stream object
		/// </summary>
		/// <param name="in"> reference to input stream object </param>
		/// <returns> reference to input stream object </returns>
		std::istream& read(std::istream& in);
	};

	/// <summary>
	/// Free Helper Function that reads information on BankAccount object specified in second parameter from 
	/// input stream object
	/// </summary>
	/// <param name="in"> reference to input stream object </param>
	/// <param name="account"> Reference to BankAccount object </param>
	/// <returns> reference to input stream object </returns>
	std::istream& operator >> (std::istream& in, BankAccount& account);

	/// <summary>
	/// Free Helper Function that writes information on BankAccount object specified in second parameter to
	/// output stream object
	/// </summary>
	/// <param name="out"> reference to input stream object </param>
	/// <param name="account"> Un-modifiable reference to BankAccount object </param>
	/// <returns> reference to input stream object </returns>
	std::ostream& operator << (std::ostream& out, const BankAccount& account);
}
#endif
