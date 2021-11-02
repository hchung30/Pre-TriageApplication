/* Citation and Sources...
Final Project Milestone 5
Module: The TriagePatient Module
Filename: TriagePatient.h
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"

namespace sdds {
	class TriagePatient : public Patient {
		char* m_symtom;
	public:
		TriagePatient();
		virtual char type() const;
		virtual ostream& csvWrite(ostream& ostr)const;
		virtual istream& csvRead(istream& istr);
		virtual ostream& write(ostream& ostr)const;
		virtual istream& read(istream& istr);
		~TriagePatient();
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


