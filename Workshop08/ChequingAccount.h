#ifndef SENECA_CHEQUINGACCOUNT_H
#define SENECA_CHEQUINGACCOUNT_H
#include "Account.h"

namespace seneca
{
	/// <summary>
	/// Class containing information on ChequingAccount (child of Account class)
	/// </summary>
	class ChequingAccount : public Account
	{
		double m_transactionFee;
		double m_monthlyFee;

	public:
		/// <summary>
		/// Parameterized ChequingAccount constructor (Special Member Function)
		/// </summary>
		/// <param name="balance"> initial account balance </param>
		/// <param name="transactionFee"> transaction fee to be applied to the balance </param>
		/// <param name="monthlyFee"> month-end fee to be applied to the account </param>
		ChequingAccount(double balance, double transactionFee, double monthlyFee);
		
		/// <summary>
		/// Credits the balance by the amount specified in the parameter and 
		/// if successful debits the transaction fee from the balance. (Modifier)
		/// </summary>
		/// <param name="amount"> amount to credit balance with </param>
		/// <returns> returns true if the transaction succeeded, false otherwise </returns>
		bool credit(double amount);

		/// <summary>
		/// Debits the balance by the amount received and 
		/// if successful debits the transaction fee from the balance. (Modifier)
		/// </summary>
		/// <param name="amount"> amount to debit balance with </param>
		/// <returns> returns true if the transaction succeeded, false otherwise </returns>
		bool debit(double amount);

		/// <summary>
		/// Debits the monthly fee from the balance, 
		/// but does not charge a transaction fee for this debit. (Modifier)
		/// </summary>
		void monthEnd();

		/// <summary>
		/// Output information on ChequingAccount (Query)
		/// </summary>
		/// <param name="out"> reference to output stream object </param>
		void display(std::ostream&) const;
	};
}
#endif
