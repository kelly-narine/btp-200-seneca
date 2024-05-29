#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H
namespace seneca
{
	/// <summary>
	/// A class that represents the IceCream object that can be ordered by the Vendor
	/// </summary>
	class IceCream
	{
		/// <summary>
		/// A statically-allocated C-style array of characters containing the IceCream flavour that can be a maxinum of 25 characters
		/// </summary>
		char m_flavour[25];

		/// <summary>
		/// number of scoops per IceCream
		/// </summary>
		int m_numOfScoops;

		/// <summary>
		/// boolean that contains whether the IceCream was orderd in a Vanilla Wafer or not
		/// </summary>
		bool m_vanillaWafer;

	public:
		/// <summary>
		/// Modifier that will set the values of the IceCream class variables to values specified by client
		/// </summary>
		/// <param name="flavour">C-style array of characters containing the IceCream flavour that can be a maxinum of 25 characters</param>
		/// <param name="cntScoops">number of scoops</param>
		/// <param name="hasVanillaWafer">true or false depending on if IceCream is ordered with Vanilla Wafer</param>
		void set(const char* flavour, int cntScoops, bool hasVanillaWafer);
		
		/// <summary>
		/// Query to obtain IceCream Flavour
		/// </summary>
		/// <returns>c-string containing flavour</returns>
		const char* getFlavour() const;

		/// <summary>
		/// Query to obtain number of scoops
		/// </summary>
		/// <returns>int containing number of scoops</returns>
		int getNumOfScoops() const;

		/// <summary>
		/// Query to obtain Vanilla Wafer boolean
		/// </summary>
		/// <returns>boolean of whether IceCream was orderd with Vanilla Wafter or not</returns>
		bool getVanillaWafer() const;
	};
}
#endif
