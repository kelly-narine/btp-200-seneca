#include <cstring>
#include <iostream>
#include "Vendor.h"
#include "IceCream.h"

namespace seneca
{
	void Vendor::startNewOrder()
	{
		if (m_order != NULL && m_numItems != 0)
		{
			closeShop();
		}
	}

	void Vendor::addToOrder(const char* flavour, int cntScoops, bool hasVanillaWafer)
	{
		// check if any parameters' data provided is not valid
		bool notValid = (flavour[0] == '\0' || cntScoops < 1 || cntScoops > 3);
		bool isSame = false;
		IceCream newIceCream = {};
		newIceCream.set(flavour, cntScoops, hasVanillaWafer);
		int orderCnt = m_numItems;
		if (orderCnt > 0 && !notValid) // if the order has already been created containing items
		{
			int i = m_numItems - 1;
			while (i > -1)
			{
				const char* existingFlavour = m_order[i].getFlavour();
			    isSame = (strcmp(existingFlavour, flavour) == 0); // check if flavour is already in order
				if (isSame)
				{
					break;
				}
				i--;
			}
			if (!isSame)
			{
				IceCream* tempOrder = new IceCream[m_numItems + 1];
				for (int j = 0; j < m_numItems; j++)
				{
					tempOrder[j] = m_order[j];
				}
				tempOrder[m_numItems] = newIceCream;
				delete[] m_order;
				m_order = tempOrder;
				m_numItems++;
			}
		}
		else // if there is nothing in the order
		{
			if (!notValid)
			{
				IceCream* tempOrder = new IceCream[m_numItems + 1];
				tempOrder[0] = newIceCream;
				m_order = tempOrder;
				m_numItems = 1;
			}
		}
	}

	double Vendor::getFlavourPrice(IceCream& iceCream) const
	{
		double flavourPrice = 0;

		if (strcmp(iceCream.getFlavour(), "Chocolate") == 0)
		{
			flavourPrice = 1.24;
		}
		else if (strcmp(iceCream.getFlavour(), "Tutti Frutti") == 0)
		{
			flavourPrice = 1.50;
		}
		else
		{
			flavourPrice = 0.99;
		}

		return flavourPrice;
	}

	double Vendor::calculateIceCreamScoopPrice(IceCream& iceCream) const
	{
		return getFlavourPrice(iceCream) * iceCream.getNumOfScoops();
	}

	double Vendor::calculateIceCreamPrice(IceCream& iceCream) const
	{
		double iceCreamPrice = 0;
		double waferPrice = 0;

		if (iceCream.getVanillaWafer())
		{
			waferPrice = 0.50;
		}

		iceCreamPrice = calculateIceCreamScoopPrice(iceCream) + waferPrice;
		return iceCreamPrice;
	}

	double Vendor::calculateSubtotal(IceCream* order) const
	{
		double subtotal = 0;
		for (int i = 0; i < m_numItems; i++)
		{
			subtotal += calculateIceCreamPrice(order[i]);
		}
		return subtotal;
	}

	double Vendor::calculateTax(IceCream* order) const
	{
		return calculateSubtotal(order) * 0.13;
	}

	double Vendor::calculateGrandTotal(IceCream* order) const
	{
		return calculateSubtotal(order) + calculateTax(order);
	}

	void Vendor::displayOrderReceipt() const
	{
		std::cout << std::endl;
		std::cout << "*********** Customer Receipt Copy ***********" << std::endl;
		// Items Ordered
		for (int i = 0; i < m_numItems; i++)
		{
			// first line
			std::cout.width(2);
			auto oldFill = std::cout.fill('#'); // orignal 
			std::cout << i + 1 << ". ";
			std::cout.fill(oldFill); // restore original to character fill set in main
			std::cout.width(36);
			oldFill = std::cout.fill('.'); // orignal
			std::cout.setf(std::ios::left);
			std::cout << m_order[i].getFlavour();
			std::cout.unsetf(std::ios::left);
			std::cout.width(5);
			std::cout.setf(std::ios::fixed);
			auto oldPrecision = std::cout.precision(2);
			std::cout << calculateIceCreamPrice(m_order[i]);
			std::cout.unsetf(std::ios::fixed);
			std::cout << std::endl;
			std::cout.fill(oldFill); // restore original to character fill set in main
			std::cout.precision(oldPrecision); // restore to original character precision set in main

			// second line
			std::cout.width(7);
			oldFill = std::cout.fill(' ');
			std::cout.setf(std::ios::fixed);
			oldPrecision = std::cout.precision(2);
			std::cout << m_order[i].getNumOfScoops() << " scoops @ " << getFlavourPrice(m_order[i]) << " each";
			std::cout.fill(oldFill);
			std::cout.width(10);
			oldFill = std::cout.fill('.'); 
			std::cout << calculateIceCreamScoopPrice(m_order[i]);
			std::cout.fill(oldFill);
			std::cout.unsetf(std::ios::fixed);
			std::cout << std::endl;
			std::cout.precision(oldPrecision);

			// third line (if wafer ordered)
			if (m_order[i].getVanillaWafer())
			{
				double waferPrice = 0.50;
				std::cout.width(11);
				oldFill = std::cout.fill(' ');
				std::cout << "Wafer";
				std::cout.fill(oldFill);
				std::cout.setf(std::ios::fixed);
				oldPrecision = std::cout.precision(2);
				std::cout.width(25);
				oldFill = std::cout.fill('.'); 
				std::cout << waferPrice;
				std::cout.fill(oldFill);
				std::cout.unsetf(std::ios::fixed);
				std::cout << std::endl;
				std::cout.precision(oldPrecision);
			}
		}

		std::cout << "\n\n";
		std::cout.setf(std::ios::fixed);
		auto oldPrecision = std::cout.precision(2);

		// Price before Tax
		std::cout.width(35);
		auto oldFill = std::cout.fill(' ');
		std::cout << "Price before tax";
		std::cout.fill(oldFill);
		std::cout.width(10);
		oldFill = std::cout.fill('.');
		std::cout << calculateSubtotal(m_order);
		std::cout.fill(oldFill);
		std::cout << std::endl;

		// Tax
		std::cout.width(35);
		oldFill = std::cout.fill(' ');
		std::cout << "Tax";
		std::cout.fill(oldFill);
		std::cout.width(10);
		oldFill = std::cout.fill('.');
		std::cout << calculateTax(m_order);
		std::cout.fill(oldFill);
		std::cout <<  std::endl;

		// Price with Tax
		std::cout.width(35);
		oldFill = std::cout.fill(' ');
		std::cout << "Price with tax";
		std::cout.fill(oldFill);
		std::cout.width(10);
		oldFill = std::cout.fill('.');
		std::cout << calculateGrandTotal(m_order);
		std::cout.fill(oldFill);
		std::cout << std::endl;

		std::cout.unsetf(std::ios::fixed);
		std::cout.precision(oldPrecision);
		std::cout.width(46);
		std::cout << "\n";
	}

	void Vendor::openShop()
	{
		m_order = nullptr;
		m_numItems = 0;
	}

	void Vendor::closeShop()
	{
		delete[] m_order;
		m_order = nullptr;
		m_numItems = 0;
	}
}
