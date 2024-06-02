#ifndef SENECA_INBOX_H
#define SENECA_INBOX_H
#include "email.h"
namespace seneca
{
	/// <summary>
	/// Class containing information on Inbox
	/// </summary>
	class Inbox
	{
		/// <summary>
		/// Dynamically-allocated array of type Email (Resource to manage)
		/// </summary>
		Email* m_emails;

		/// <summary>
		/// Number of Emails in Inbox
		/// </summary>
		int m_cntEmails;

	public:
		/// <summary>
		/// Default Inbox Constructor
		/// </summary>
		Inbox();

		/// <summary>
		/// Inbox Copy-Constructor (Component in Rule-of-Three)
		/// </summary>
		/// <param name="inbox"> Un-modifiable reference to object of type Inbox </param>
		Inbox(const Inbox&);

		/// <summary>
		/// Inbox Copy-Assignment Operator (Component in Rule-of-Three)
		/// </summary>
		/// <param name="inbox"> Un-modifiable reference to object of type Inbox </param>
		/// <returns> Reference to current object of type Inbox </returns>
		Inbox& operator = (const Inbox&); // copy-assignment operator

		/// <summary>
		/// Inbox Destructor (Component in Rule-of-Three)
		/// </summary>
		~Inbox();

		/// <summary>
		/// Adds object of type Email to Inbox (Modifier)
		/// </summary>
		/// <param name="email"> Un-modifiable reference to object of type Email </param>
		/// <returns> Reference to current object of type Inbox </param>
		Inbox& operator += (const Email&);

		/// <summary>
		/// Add object of type Email to Inbox
		/// </summary>
		/// <param name="email"> Un-modifiable reference to object of type Email </param>
		/// <returns> Object of type Inbox </returns>
		Inbox operator + (const Email&) const;

		/// <summary>
		/// Loads a collection of emails from a file and adds them to the current Inbox instance (Modifier)
		/// </summary>
		/// <param name="fileName"> Name of file containing Emails to load </param>
		void load(const char* fileName);

		/// <summary>
		/// Saves Emails stored in Inbox to file specified in parameter (Query)
		/// </summary>
		/// <param name="fileName"> Name of file to save Inbox Emails to </param>
		void save(const char* fileName) const;

		/// <summary>
		/// Friend Helper Function that overloads insertion operator 
		/// to insert object of type Inbox into output stream
		/// </summary>
		/// <param name="out"> Reference to object of type std::ostream (output stream) </param>
		/// <param name="inbox"> Un-modifiable reference to object of type Inbox </param>
		/// <returns> Reference to output stream </returns>
		friend std::ostream& operator << (std::ostream& out, const Inbox& inbox);
	};
}
#endif 
