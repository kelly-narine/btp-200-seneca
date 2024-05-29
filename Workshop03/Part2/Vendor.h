#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H

#include "IceCream.h"

namespace seneca
{
	/// <summary>
	/// A class that represents the Vendor object that will manage the IceCream orders
	/// </summary>
	class Vendor
	{
		/// <summary>
		/// Dynamically allocated array of IceCream objects that contains all the IceCreams in an order
		/// </summary>
		IceCream* m_order;

		/// <summary>
		/// Int value containing the number of IceCream objects in an order
		/// </summary>
		int m_numItems;

	public:
		/// <summary>
		/// Deallocates any dynamic memory used by the object and sets it to an empty state.
		/// </summary>
		void startNewOrder();
		
		/// <summary>
		/// Modifier that creates a new IceCream object and adds it to the collection of ice cream that 
		/// the customer ordered only if the collection doesn't already contain that flavour 
		/// and all the parameters are valid.
		/// </summary>
		/// <param name="flavour">address of c-string containing IceCream flavour</param>
		/// <param name="cntScoops">number of scoops</param>
		/// <param name="hasVanillaWafer">boolean if IceCream ordered with Vanilla Wafer or not</param>
		void addToOrder(const char* flavour, int cntScoops, bool hasVanillaWafer);

		/// <summary>
		/// Query to obtain the price of an IceCream's flavour
		/// </summary>
		/// <param name="iceCream"> reference of IceCream object </param>
		/// <returns>double value containing the price of specified IceCream flavour</returns>
		double getFlavourPrice(IceCream& iceCream) const;

		/// <summary>
		/// Query that calculates the price of only the scoops of IceCream
		/// </summary>
		/// <param name="iceCream">reference of IceCream object</param>
		/// <returns>double value containing the price of the scoops of IceCream</returns>
		double calculateIceCreamScoopPrice(IceCream& iceCream) const;

		/// <summary>
		/// Query that calculates the price of a single IceCream object (not including taxes)
		/// </summary>
		/// <param name="iceCream">reference of IceCream object</param>
		/// <returns>double value containing the price of a single IceCream object (not including taxes)</returns>
		double calculateIceCreamPrice(IceCream& iceCream) const;

		/// <summary>
		/// Query that calculates subtotal cost of order before taxes
		/// </summary>
		/// <param name="order">address of order array (array of IceCream objects) </param>
		/// <returns>double value containing the order's subtotal cost before taxes</returns>
		double calculateSubtotal(IceCream* order) const;

		/// <summary>
		/// Query that calculates the order's taxes
		/// </summary>
		/// <param name="order">address of order array (array of IceCream objects) </param>
		/// <returns>double value containing the order's taxes</returns>
		double calculateTax(IceCream* order) const;

		/// <summary>
		/// Query that calculates grand total cost of order including taxes
		/// </summary>
		/// <param name="order">address of order array (array of IceCream objects) </param>
		/// <returns>double value containing the order's grand total cost including taxes</returns>
		double calculateGrandTotal(IceCream* order) const;
		
		/// <summary>
		/// Query that outputs the order's receipt 
		/// </summary>
		void displayOrderReceipt() const;

		/// <summary>
		/// Initializes the object to a default state (initializes all the attributes to some default value 
		/// or empty state
		/// </summary>
		void openShop();

		/// <summary>
		/// Deallocates any dynamic memory used by the object and sets it to an empty state.
		/// </summary>
		void closeShop();
	};
}
#endif
