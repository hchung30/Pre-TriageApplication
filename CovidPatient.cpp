/* Citation and Sources...
Final Project Milestone 5
Module: The Patient Module
Filename: CovidPatient.cpp
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "CovidPatient.h"
namespace sdds {
	int nextCovidTicket = 1;
	CovidPatient::CovidPatient() : Patient(nextCovidTicket)
	{
		nextCovidTicket++;
	}

	char CovidPatient::type() const
	{
		return 'C';
	}
	istream& CovidPatient::csvRead(istream& istr)
	{
		int ticNum;
		Patient::csvRead(istr);
		ticNum = number() + 1;
		nextCovidTicket = ticNum;
		istr.ignore(10000, '\n');
		return istr;
	}

	ostream& CovidPatient::write(ostream& ostr) const
	{
		if (fileIO() == true) {
			Patient::csvWrite(ostr);
		}
		else {
			ostr << "COVID TEST" << endl;
			Patient::write(ostr);
			ostr << endl;
		}
		return ostr;

	}
	istream& CovidPatient::read(istream& istr)
	{
		if (fileIO() == true) {
			csvRead(istr);
		}
		else {
			Patient::read(istr);
		}
		return istr;
	}
}