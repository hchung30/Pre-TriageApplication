/* Citation and Sources...
Final Project Milestone 5
Module: The Patient Module
Filename: Patient.cpp
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Patient.h"
using namespace std;
namespace sdds {
	Patient::Patient(int ticketNum, bool IOFlag) : m_name(nullptr), m_ohip(0), m_ticket(Ticket(ticketNum)), m_IOFlag(IOFlag)
	{
	}

	Patient::~Patient()
	{
		delete[] m_name;
	}

	bool Patient::fileIO() const
	{
		return m_IOFlag;
	}

	void Patient::fileIO(bool IOflag)
	{
		m_IOFlag = IOflag;
	}

	bool Patient::operator==(char ch) const
	{
		if (this->type() == ch) {
			return true;
		}
		return false;
	}

	bool Patient::operator==(const Patient& p) const
	{
		if (this->type() == p.type()) {
			return true;
		}
		return false;
	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}

	Patient::operator Time() const
	{
		return (Time)m_ticket;
	}

	int Patient::number() const
	{
		return m_ticket.number();
	}

	ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << this->type() << "," << m_name << "," << m_ohip << ",";
		m_ticket.csvWrite(ostr);

		return ostr;
	}

	istream& Patient::csvRead(std::istream& istr)
	{
		if (m_name != nullptr) {
			delete[] m_name;
			m_name = nullptr;
		}
		m_name = getcstr(nullptr, istr, ',');
		istr >> m_ohip;
		istr.ignore(1000, ',');
		m_ticket.csvRead(istr);
		return istr;
	}

	ostream& Patient::write(ostream& ostr) const
	{
		m_ticket.write(ostr);
		ostr << endl;
		char name[26] = { 0 };
		strncpy(name, m_name, 25);
		ostr << name << ", OHIP: " << m_ohip;
		return ostr;
	}

	istream& Patient::read(istream& istr)
	{
		if (m_name != nullptr) {
			delete[] m_name;
			m_name = nullptr;
		}
		m_name = getcstr("Name: ", istr);
		m_ohip = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number");
		return istr;
	}
}