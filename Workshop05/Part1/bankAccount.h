#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H
namespace seneca
{
	/// <summary>
	/// class containing information on BankAccount
	/// </summary>
	class BankAccount
	{
		/// <summary>
		/// Statically-allocated char array containing BankAccount owner name
		/// </summary>
		char m_userName[100];

		/// <summary>
		/// Balance of BankAccount
		/// </summary>
		double m_balance;

		/// <summary>
		/// BankAccount type; true if checking, false if savings
		/// </summary>
		bool m_checking;

		/// <summary>
		/// Number of transactions in BankAccount
		/// </summary>
		int m_transactions;

	public:
		/// <summary>
		/// Custom BankAccount Constructor (Special Member Function)
		/// </summary>
		/// <param name="name"> Name of BankAccount owner </param>
		/// <param name="checking"> BankAccount type; true if checking, false if savings </param>
		BankAccount(const char* name = nullptr, bool checking = false);

		/// <summary>
		/// Conversion-to-Bool Operator that checks if BankAccount is open or not (Query)
		/// </summary>
		operator bool() const;

		/// <summary>
		/// Conversion-to-Double Operator that returns BankAccount balance (Query)
		/// </summary>
		operator double() const;

		/// <summary>
		/// Conversion-to-String Operator that returns the address of the BankAccount owner (Query)
		/// </summary>
		operator const char* () const;

		/// <summary>
		/// Conversion-to-Int Operator that returns the number of transactions done with BankAccount
		/// (Query)
		/// </summary>
		operator int() const;

		/// <summary>
		/// Overloaded += operator to add specified deposit amount in parameter to BankAccount balance
		/// (Modifier)
		/// </summary>
		/// <param name="amount"> amount of money to deposit to the BankAccount </param>
		/// <returns> reference to current BankAccount instance </returns>
		BankAccount& operator += (double amount);

		/// <summary>
		/// Overloaded -= operator to subract specified withdrawal amount in parameter 
		/// from BankAccount balance (Modifier)
		/// </summary>
		/// <param name="amount"> amount of money to withdraw from the BankAccount </param>
		/// <returns> reference to current BankAccount instance </returns>
		BankAccount& operator -= (double amount);

		/// <summary>
		/// Pre-fix operator that adds interest to the BankAccount balance (Modifier)
		/// </summary>
		/// <returns> reference to updated BankAccount instance with interest added to 
		/// the balance </returns>
		BankAccount& operator++();

		/// <summary>
		/// Post-fix operator that adds interest to the BankAccount balance (Modifier)
		/// </summary>
		/// <returns> BankAccount object before interest is added to the balance </returns>
		BankAccount operator++(int); 

        /// <summary>
		/// Overloaded > operator.
        /// Checks if BankAccount balance is greater than the amount specified in parameter (Query)
        /// </summary>
        /// <param name="amount"> amount to compare balance to </param>
        /// <returns> true if balance in BankAccount is greater than amount specified in 
		/// parameter, otherwise false </returns>
        bool operator > (double amount) const;

		/// <summary>
		/// Overloaded + operator. 
		/// Creates a new BankAccount and deposits amount specified in parameter (Query)
		/// </summary>
		/// <param name="amount"> amount to deposit inside newly created BankAccount </param>
		/// <returns> BankAccount object </returns>
		BankAccount operator+(double amount) const;

		/// <summary>
		/// Ouputs content of BankAccount (Query)
		/// </summary>
		void display() const;
	};

	/// <summary>
	/// Free Helper Function to check if amount specified in parameter is greater than BankAccount
	/// balance
	/// </summary>
	/// <param name="amount"> amount to compare balance to </param>
	/// <param name="account"> account to obtain balance for comparison </param>
	/// <returns> true if the amount specified in parameter is greater than balance in BankAccount, 
	/// otherwise false </returns>
	bool operator > (double amount, const BankAccount& account);
}
#endif
