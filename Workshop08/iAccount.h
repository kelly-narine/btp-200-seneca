#ifndef SENECA_IACCOUNT_H
#define SENECA_IACCOUNT_H
#include <iostream>
namespace seneca
{
	/// <summary>
	/// iAccount Abstract Class (Interface)
	/// </summary>
	class iAccount
	{
	public:
		/// <summary>
		/// Pure virtual function that adds a positive amount to the account balance
		/// </summary>
		/// <param name="amount"> amount to add to Account balance </param>
		/// <returns> true if transaction is successful, false otherwise </returns>
		virtual bool credit(double amount) = 0;

		/// <summary>
		/// Pure virtual function that subtracts a positive amount from the account balance
		/// </summary>
		/// <param name="amount"> amount to subtract from Account balance </param>
		/// <returns> true if transaction is successful, false otherwise </returns>
		virtual bool debit(double amount) = 0;

		/// <summary>
		/// Pure virtual function applies month-end transactions to the account
		/// </summary>
		virtual void monthEnd() = 0;

		/// <summary>
		/// Pure virtual function that inserts account information into an ostream object
		/// </summary>
		/// <param name="out"> reference to ouput stream object </param>
		virtual void display(std::ostream&) const = 0;

		/// <summary>
		/// iAccount Virtual Destructor
		/// </summary>
		virtual ~iAccount() = default; // default allows compiler to do the implementation for you 
	};
	
	/// <summary>
	/// Global Helper Function that creates the account with the starting balance and returns its address
	/// </summary>
	/// <param name="type"> type of Account </param>
	/// <param name="balance"> initial Account balance </param>
	/// <returns></returns>
	iAccount* CreateAccount(const char* type, double balance);
}
#endif 
