/* Citation and Sources...
Final Project Milestone 5
Module: IOAble interface
Filename: IOAble.h
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>
using namespace std;
namespace sdds {
	class IOAble {
	public:
		virtual ostream& csvWrite(std::ostream& ostr)const = 0;
		virtual istream& csvRead(std::istream& istr) = 0;
		virtual ostream& write(ostream& ostr)const = 0;
		virtual istream& read(istream& istr) = 0;
		virtual ~IOAble();
	};
	std::ostream& operator<<(std::ostream& ostr, const IOAble& IO);
	std::istream& operator>>(std::istream& istr, IOAble& IO);
}
#endif