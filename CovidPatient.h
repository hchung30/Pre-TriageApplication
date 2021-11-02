/* Citation and Sources...
Final Project Milestone 5
Module: The CovidPatient Module
Filename: CovidPatient.h
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"

using namespace std;
namespace sdds {
	class CovidPatient : public Patient {
	public:
		CovidPatient();
		virtual char type() const;
		virtual istream& csvRead(istream& istr);
		virtual ostream& write(ostream& ostr)const;
		virtual istream& read(istream& istr);
	};
}
#endif // !SDDS_COVIDPATIENT_H_



