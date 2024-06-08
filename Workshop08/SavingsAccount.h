#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "Account.h"

namespace seneca
{
	/// <summary>
	/// Class containing information on SavingsAccount (child of Account class)
	/// </summary>
	class SavingsAccount : public Account
	{
		double m_interestRate;

	public:
		/// <summary>
		/// Parameterized SavingsAccount Constructor (Special Member Function)
		/// </summary>
		/// <param name="balance"> initial account balance </param>
		/// <param name="interestRate"> interest rate that applies to the account </param>
		SavingsAccount(double balance, double interestRate);

		/// <summary>
		/// calculates the interest earned on the current balance and 
		/// credits the account with that interest (Modifier)
		/// </summary>
		void monthEnd();

		/// <summary>
		/// Output information on SavingsAccount (Query)
		/// </summary>
		/// <param name="out"> reference to output stream object </param>
		void display(std::ostream&) const;
	};
}
#endif
