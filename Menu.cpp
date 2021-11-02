/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
using namespace std;

namespace sdds {
	void Menu::display() const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}

	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		m_text = nullptr;
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}
	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfSel, "> ", "Bad integer value, try again: ", true);
		return Selection;
	}
	Menu::Menu(const Menu& copy)
	{
		m_text = nullptr;
		m_noOfSel = copy.m_noOfSel;
		m_text = new char[strlen(copy.m_text) + 1];
		strcpy(m_text, copy.m_text);
	}
}