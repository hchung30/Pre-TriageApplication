/* Citation and Sources...
Final Project Milestone 5
Module: IOAble interface
Filename: IOAble.cpp
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "IOAble.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const IOAble& IO)
	{
		IO.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, IOAble& IO)
	{
		IO.read(istr);
		return istr;
	}
	IOAble::~IOAble()
	{
	}
}