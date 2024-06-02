#ifndef SENECA_EMAIL_H
#define SENECA_EMAIL_H
namespace seneca
{
	/// <summary>
	/// Class containing information about Email
	/// </summary>
	class Email
	{
		/// <summary>
		/// Statically-allocated array of characters that contains name of sender of Email
		/// </summary>
		char m_fromName[100];

		/// <summary>
		/// Statically-allocated array of characters that contains email address of Email
		/// </summary>
		char m_fromAddress[100];

		/// <summary>
		/// Statically-allocated array of characters that contains date Email was recieved
		/// </summary>
		char m_dateReceived[20];

		/// <summary>
		/// Dynamically-allocated array of characters containing subject of email (resource to manage)
		/// </summary>
		char* m_subject; 

	public:
		/// <summary>
		/// Default Email Constructor
		/// </summary>
		Email();
		
		/// <summary>
		/// Email Copy-Constructor (Component in Rule-of-Three)
		/// </summary>
		/// <param name="email"> Un-modifiable reference to object of type Email </param>
		Email(const Email&); 

		/// <summary>
		/// Email Copy-Assignment Operator (Component in Rule-of-Three)
		/// </summary>
		/// <param name="email"> Un-modifiable reference to object of type Email </param>
		/// <returns> Reference to current object of type Email </returns>
		Email& operator = (const Email&); // copy-assignment operator
		
		/// <summary>
		/// Email Destructor (Component in Rule-of-Three)
		/// </summary>
		~Email();

		/// <summary>
		/// Loads data from an input stream and stores it into the current instance (Modifier)
		/// </summary>
		/// <param name="in"> Reference to an object of type std::istream (input stream) </param>
		/// <returns> true if data was successfully loaded, false otherwise </returns>
		bool load(std::istream& in);

		/// <summary>
		/// Friend Helper Function with formatted output of Email object information
		/// </summary>
		/// <param name="out"> Reference to object of type std::ostream (output stream) </param>
		/// <param name="email"> Un-modifiable reference to object of type Email </param>
		friend void outputEmails(std::ostream& out, const Email& email);

		/// <summary>
		/// Friend Helper Function that overloads insertion operator 
		/// to insert object of type Email into output stream
		/// </summary>
		/// <param name="out"> Reference to object of type std::ostream (output stream) </param>
		/// <param name="email"> Un-modifiable reference to object of type Email </param>
		/// <returns> Reference to output stream </returns>
		friend std::ostream& operator<<(std::ostream& out, const Email& email);
	};
}
#endif

