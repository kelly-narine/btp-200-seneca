/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/03/15  Preliminary release
-----------------------------------------------------------
*/

#include "IOAble.h"

namespace seneca
{
	IOAble::~IOAble() {}

	std::istream& operator>>(std::istream& in, IOAble& ioAble)
	{
		ioAble.read(in);
		return in;
	}

	std::ostream& operator<<(std::ostream& out, const IOAble& ioAble)
	{
		ioAble.write(out);
		return out;
	}
}

