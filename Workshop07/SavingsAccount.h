#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "DepositUtility.h"
#include "BankAccount.h"
namespace seneca
{
	/// <summary>
	/// Class Containing information on SavingsAccount (Derived Class from BankAccount Class)
	/// </summary>
	class SavingsAccount: public BankAccount
	{
		/// <summary>
		/// floating-point number in double precision representing 
		/// the interest rate that must be paid on the balance
		/// </summary>
		double m_interest;

		/// <summary>
		/// Date when the interest was last applied to the account
		/// </summary>
		Date m_interestDate;

		/// <summary>
		/// Write the amount of interest SavingsAccount in 0.045% format to output stream object
		/// </summary>
		/// <param name="out"> reference to output stream object </param>
		void writeInterest(std::ostream& out) const;

	public:

		/// <summary>
		/// SavingsAccount Constructor (Special Member Function)
		/// </summary>
		/// <param name="name"> name of SavingsAccount owner </param>
		/// <param name="openDate"> Date SavingsAccount Opened </param>
		/// <param name="depInfo"> Deposit Information for SavingsAccount </param>
		/// <param name="balance"> balance in the SavingsAccount </param>
		/// <param name="interest"> interest rate that must be paid on the balance </param>
		/// <param name="interestDate"> Date when the interest was last applied to the account </param>
		SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, 
			double interest, Date interestDate);
		
		/// <summary>
		/// Increases SavingsAccount balance by adding interest
		/// </summary>
		/// <param name="today"> Un-modifiable reference to an object of type seneca::Date</param>
		void applyInterest(const Date& today);
		
		/// <summary>
		/// Write information on the current SavingsAccount object to the output object
		/// </summary>
		/// <param name="out"> reference to output stream object </param>
		/// <returns> reference to output stream object </returns>
		std::ostream& write(std::ostream& out) const;
		
		/// <summary>
		/// Read information entered for SavingsAccount from input stream object
		/// </summary>
		/// <param name="in"> reference to input stream object </param>
		/// <returns> reference to input stream object </returns>
		std::istream& read(std::istream& in);
	};

	/// <summary>
	/// Free Helper Function that reads information on SavingsAccount object 
	/// specified in second parameter from input stream object
	/// </summary>
	/// <param name="in"> reference to input stream object </param>
	/// <param name="account"> Reference to SavingsAccount object </param>
	/// <returns> reference to input stream object </returns>
	std::istream& operator >> (std::istream& in, SavingsAccount& account);
	
	/// <summary>
	/// Free Helper Function that writes information on SavingsAccount object specified in second parameter to
	/// output stream object
	/// </summary>
	/// <param name="out"> reference to input stream object </param>
	/// <param name="account"> Un-modifiable reference to SavingsAccount object </param>
	/// <returns> reference to input stream object </returns>
	std::ostream& operator << (std::ostream& out, const SavingsAccount& account);
}
#endif
