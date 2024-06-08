#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include "iAccount.h"
namespace seneca
{
	/// <summary>
	/// Class containing information on Account (derived from iAccount interface)
	/// </summary>
	class Account: public iAccount
	{
		double m_balance;

	public:
		/// <summary>
		/// Parameterized Account constructor (Special Member Function)
		/// </summary>
		/// <param name="balance"> initial Account balance (zero by default if not specified) </param>
		Account(double balance = 0.0);

		/// <summary>
		/// Credits the balance by the amount specified in the parameter (Modifier)
		/// </summary>
		/// <param name="amount"> amount to credit balance with </param>
		/// <returns> returns true if the transaction succeeded, false otherwise </returns>
		bool credit(double amount);

		/// <summary>
		/// Debits the balance by the amount specified in the parameter (Modifier)
		/// </summary>
		/// <param name="amount"> amount to debit balance with </param>
		/// <returns> returns true if the transaction succeeded, false otherwise </returns>
		bool debit(double amount);
	
	protected:
		/// <summary>
		/// Returns the current balance of the account (Query)
		/// </summary>
		/// <returns></returns>
		double balance() const;
	};
}
#endif
