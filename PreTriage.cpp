/* Citation and Sources...
Final Project Milestone 5
Module: The PreTriage Module
Filename: PreTriage.h
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "PreTriage.h"

using namespace std;
namespace sdds {
	PreTriage::PreTriage(const char* dataFilename) : m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		m_averCovidWait = 15;
		m_averTriageWait = 5;
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}

	PreTriage::~PreTriage()
	{
		ofstream fout(m_dataFilename);
		ifstream fin(m_dataFilename);
		int i;
		cout << "Saving Average Wait Times," << endl;
		fout << (Time)m_averCovidWait << "," << (Time)m_averTriageWait << endl;
		cout << "   COVID Test: " << (Time)m_averCovidWait << endl;
		cout << "   Triage: " << (Time)m_averTriageWait << endl;
		cout << "Saving m_lineup..." << endl;
		for (int i = 0; i < m_lineupSize; i++) {
			cout << i + 1 << "- ";
			m_lineup[i]->csvWrite(cout) << endl;
			m_lineup[i]->csvWrite(fout) << endl;
		}
		fout.close();

		for (i = 0; i < maxNoOfPatients; i++) {
			delete m_lineup[i];
		}
		delete[] m_dataFilename;
		cout << "done!" << endl;

	}

	void PreTriage::run(void)
	{
		int selection;
		while (m_appMenu >> selection) {
			switch (selection) {
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			case 0:
				break;
			}
		}
	}

	void PreTriage::reg()
	{
		if (m_lineupSize >= maxNoOfPatients) {
			cout << "Line up full!" << endl;
			return;
		}
		int selection = -1;
		selection = m_pMenu.operator>>(selection);
		if (selection == 1) {
			m_lineup[m_lineupSize] = new CovidPatient();
		}
		else if (selection == 2) {
			m_lineup[m_lineupSize] = new TriagePatient();
		}
		else {
			return;
		}
		m_lineup[m_lineupSize]->setArrivalTime();
		cout << "Please enter patient information: " << endl;
		m_lineup[m_lineupSize]->fileIO(false);
		m_lineup[m_lineupSize]->read(cin);
		cout << endl;
		cout << "******************************************" << endl;
		m_lineup[m_lineupSize]->write(cout);
		cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
		cout << "******************************************" << endl << endl;
		m_lineupSize++;
	}

	void PreTriage::admit()
	{
		int i;
		int index = -1;
		int selection = 1;
		while (selection) {
			m_pMenu >> selection;
			switch (selection) {
			case 1:
				for (i = 0; i < m_lineupSize; i++) {
					if (m_lineup[i]->type() == 'C') {
						index = i;
						selection = 0;
						break;
					}
				}
				break;
			case 2:
				for (i = 0; i < m_lineupSize; i++) {
					if (m_lineup[i]->type() == 'T') {
						index = i;
						selection = 0;
						break;
					}
				}
				break;
			default:
				break;
			}
			if (index != -1) {
				cout << endl;
				cout << "******************************************";
				cout << endl;
				cout << "Calling for ";
				m_lineup[index]->write(cout);
				cout << "******************************************";
				cout << endl << endl;

				setAverageWaitTime(*m_lineup[index]);

				removePatientFromLineup(index);
			}
		}
	}

	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		unsigned int count = 0;
		int i;
		for (i = 0; i < maxNoOfPatients; i++) {
			if (m_lineup[i] != nullptr) {
				if (m_lineup[i]->type() == p.type()) {
					count++;
				}
			}
		}
		return p.type() == 'C' ? (Time)m_averCovidWait *= (count - 1) : (Time)m_averTriageWait *= (count - 1);
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		int ct = getTime();
		int ptt = (int)((Time)p);
		int awt;
		int ptn = (int)((Time)p.number());
		//AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN
		if (p.type() == 'C') {
			awt = (int)m_averCovidWait;
			m_averCovidWait = ((ct - ptt) + (awt * (ptn - 1))) / ptn;
		}
		else {
			awt = (int)m_averTriageWait;
			m_averTriageWait = ((ct - ptt) + (awt * (ptn - 1))) / ptn;
		}
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int i;
		for (i = 0; i < m_lineupSize; i++) {
			if (m_lineup[i]->type() == type) {
				return i;
			}
		}
		return -1;
	}

	void PreTriage::load()
	{
		Patient* p = nullptr;
		cout << "Loading data..." << endl;
		ifstream fin(m_dataFilename);

		if (fin.is_open()) {
			m_averCovidWait.read(fin);
			fin.ignore(1000, ',');
			m_averTriageWait.read(fin);
		}
		fin.ignore(1000, '\n');
		int i;
		char ch;
		for (i = 0; i < maxNoOfPatients && !fin.eof(); i++) {
			fin >> ch;
			fin.ignore(1000, ',');
			if (ch == 'C') {
				p = new CovidPatient();
			}
			else if (ch == 'T') {
				p = new TriagePatient();
			}

			if (p != nullptr) {
				p->fileIO(true);
				p->read(fin);
				p->fileIO(false);
				m_lineup[i] = p;
				m_lineupSize++;
				p = nullptr;
				ch = '\0';
			}
		}
		if (!fin.eof()) {
			cout << "Warning: number of records exceeded 100" << endl;
			cout << m_lineupSize << " Records imported..." << endl;
		}
		else if (m_lineupSize == 0) {
			cout << "No data or bad data file!" << endl;
		}
		else {
			cout << m_lineupSize << " Records imported..." << endl;
		}
		cout << endl;

	}
}