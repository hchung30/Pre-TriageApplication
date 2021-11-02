/* Citation and Sources...
Final Project Milestone 5
Module: The TriagePatient Module
Filename: TriagePatient.cpp
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "TriagePatient.h"
namespace sdds {
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() : Patient(nextTriageTicket)
	{
		m_symtom = nullptr;
		nextTriageTicket++;
	}

	char TriagePatient::type() const
	{
		return 'T';
	}

	ostream& TriagePatient::csvWrite(ostream& ostr) const
	{
		Patient::csvWrite(ostr);
		ostr << "," << m_symtom;
		return ostr;
	}

	istream& TriagePatient::csvRead(istream& istr)
	{
		delete[] m_symtom;
		Patient::csvRead(istr);
		istr.ignore(1000, ',');
		m_symtom = getcstr(nullptr, istr, '\n');
		nextTriageTicket = number() + 1;
		return istr;
	}

	ostream& TriagePatient::write(ostream& ostr) const
	{
		if (fileIO() == true) {
			csvWrite(ostr);
		}
		else {
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << endl;
			ostr << "Symptoms: " << m_symtom << endl;
		}
		return ostr;
	}

	istream& TriagePatient::read(istream& istr)
	{
		if (fileIO() == true) {
			csvRead(istr);
		}
		else {
			if (m_symtom != nullptr) {
				delete[] m_symtom;
			}
			Patient::read(istr);
			m_symtom = getcstr("Symptoms: ", istr, '\n');
		}
		return istr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symtom;
	}

}