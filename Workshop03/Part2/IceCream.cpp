#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "IceCream.h"

namespace seneca
{
	void IceCream::set(const char* flavour, int cntScoops, bool hasVanillaWafer)
	{
		strcpy(m_flavour, flavour); 
		m_numOfScoops = cntScoops;
		m_vanillaWafer = hasVanillaWafer;
	}

	const char* IceCream::getFlavour() const
	{
		return m_flavour;
	}

	int IceCream::getNumOfScoops() const
	{
		return m_numOfScoops;
	}

	bool IceCream::getVanillaWafer() const
	{
		return m_vanillaWafer;
	}
}
