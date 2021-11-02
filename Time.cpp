/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.cpp
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Time.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow()
	{
		this->m_min = getTime();
		return *this;
	}
	Time::Time(unsigned int min)
	{
		m_min = min;
	}
	std::ostream& Time::write(std::ostream& ostr) const
	{
		int h;
		int m;
		h = this->m_min / 60;
		m = this->m_min % 60;
		ostr.setf(ios::fixed);
		ostr.width(2);
		ostr.fill('0');
		ostr << h;
		ostr << ":";
		ostr.setf(ios::fixed);
		ostr.width(2);
		ostr.fill('0');
		ostr << m;

		return ostr;
	}
	std::istream& Time::read(std::istream& istr)
	{
		int hours = 0;
		char ch = 'x';
		int mins = 0;
		istr >> hours;
		istr >> ch;
		istr >> mins;

		if (hours < 0 || mins < 0 || ch != ':') {
			istr.setstate(ios::failbit);
		}
		else {
			this->m_min = (hours * 60) + mins;
		}

		return istr;
	}
	Time& Time::operator-=(const Time& D)
	{
		while (this->m_min < D.m_min) {
			this->m_min += 1440;
		}
		this->m_min -= D.m_min;
		return *this;
	}
	Time Time::operator-(const Time& D) const
	{
		unsigned mins = this->m_min;
		while (mins < D.m_min) {
			mins += 1440;
		}

		Time t(mins - D.m_min);
		return t;
	}

	Time& Time::operator+=(const Time& D)
	{
		this->m_min += D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D) const
	{
		Time t(this->m_min + D.m_min);
		return t;
	}
	Time& Time::operator=(unsigned int val)
	{
		this->m_min = val;
		return *this;

	}
	Time& Time::operator*=(unsigned int val)
	{
		this->m_min *= val;
		return *this;

	}
	Time& Time::operator/=(unsigned int val)
	{
		this->m_min /= val;
		return *this;
	}
	Time Time::operator*(unsigned int val) const
	{
		Time t(this->m_min * val);
		return t;
	}

	Time Time::operator/(unsigned int val) const
	{
		Time t(this->m_min / val);
		return t;
	}

	Time::operator unsigned int() const
	{
		return m_min;
	}

	Time::operator int() const
	{
		return m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		D.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Time& D)
	{
		D.read(istr);
		return istr;
	}
}