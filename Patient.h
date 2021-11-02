/* Citation and Sources...
Final Project Milestone 5
Module: The Patient Module
Filename: Patient.h
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"
#include "utils.h"

using namespace std;
namespace sdds {
	class Patient : public IOAble {
		char* m_name;
		int m_ohip;
		Ticket m_ticket;
		bool m_IOFlag;
	public:
		Patient(int ticketNum = 0, bool IOFlag = false);
		~Patient();
		Patient(const Patient& copy) = delete;
		Patient& operator=(const Patient& copy) = delete;
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool IOflag);
		bool operator==(char ch) const;
		bool operator==(const Patient& p) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		virtual ostream& csvWrite(ostream& ostr)const;
		virtual istream& csvRead(istream& istr);
		virtual ostream& write(ostream& ostr)const;
		virtual istream& read(istream& istr);
	};
}
#endif