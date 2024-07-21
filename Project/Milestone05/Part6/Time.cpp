/* Citation and Sources...
Final Project Milestone 5, Part 6
Module: Time
Filename: Time.cpp
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/03/31  Preliminary release
-----------------------------------------------------------
*/

#include "Time.h"
#include "Utils.h"
namespace seneca
{
	Time::Time(unsigned int min)
	{
		m_minutes = min;
	}

	Time& Time::reset()
	{
		m_minutes = U.getTime();
		return *this;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hrs = m_minutes / 60;
		int mins = m_minutes % 60;
		ostr.width(2);
		ostr.fill('0');
		ostr << hrs;
		ostr << ":";
		ostr.width(2);
		ostr << mins;
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hrs = 0;
		int mins = 0;

		istr >> hrs;
		if (istr.peek() != ':') // peek checks the next character without extracting it
		{
			istr.setstate(std::ios::failbit);
		}
		else
		{
			istr.ignore(); // discards :
		}
		istr >> mins;
		m_minutes = (hrs * 60) + mins;
		
		return istr;
	}

	Time::operator unsigned int() const
	{
		return m_minutes;
	}

	Time& Time::operator*= (int val)
	{
		m_minutes *= val;
		return *this;
	}

	Time& Time::operator-= (const Time& D)
	{
		int difference = m_minutes - D.m_minutes;
		if (difference < 0)
		{
			m_minutes = (m_minutes + 1440) - D.m_minutes;
		}
		else
		{
			m_minutes = difference;
		}
		return *this;
	}

	Time Time::operator-(const Time& T)const
	{
		Time updatedTime = Time();
		updatedTime.m_minutes = (int)*this;
		updatedTime -= T;
		return updatedTime;
	}

	std::istream& operator>>(std::istream& istr, Time& time)
	{
		return time.read(istr);
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& time)
	{
		return time.write(ostr);
	}
}
