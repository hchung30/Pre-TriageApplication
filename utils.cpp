/* Citation and Sources...
Final Project Milestone 5
Module: utils
Filename: utils.cpp
Version 1.0
Author	Heather Chung

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
	int strLen(const char* s) {
		int i = 0;
		while (s[i] != '\0') {
			i++;
		}
		return i;
	}

	bool debug = false;  // made global in utils.h
	int getTime() {
		int mins = -1;
		if (debug) {
			Time t(0);
			cout << "Enter current time: ";
			do {
				cin.clear();
				cin >> t;   // needs extraction operator overloaded for Time
				if (!cin) {
					cout << "Invlid time, try agian (HH:MM): ";
					cin.clear();
				}
				else {
					mins = int(t);
				}
				cin.ignore(1000, '\n');
			} while (mins < 0);
		}
		else {
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}
	int getInt(const char* prompt)
	{
		int num;
		char ch;
		if (prompt) cout << prompt;
		cin >> num;
		ch = cin.get();
		while (cin.fail() || ch != '\n') {
			if (num == 0 && ch != '\n') {
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> num;
				ch = cin.get();
			}
			else if (ch != '\n') {
				cout << "Enter only an integer, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> num;
				ch = cin.get();
			}
		}
		return num;
	}
	int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
	{
		int num = getInt(prompt);
		while (num < min || num > max) {
			if (showRangeAtError) {
				if (errorMessage != nullptr) {
					cout << errorMessage << ", [" << min << " <= value <= " << max << "]: ";
				}
				else {

					cout << "Invalid option [" << min << " <= value <= " << max << "]: ";
				}
			}
			else {
				cout << "Value must be between " << min << " and " << max << ": ";
			}
			num = getInt();
		}
		return num;
	}
	char* getcstr(const char* prompt, std::istream& istr, char delimiter)
	{
		char* str = nullptr;
		string temp;
		if (prompt != nullptr) {
			cout << prompt;
		}
		if (getline(istr, temp, delimiter)) {
			str = new char[strlen(temp.c_str()) + 1];
			strcpy(str, temp.c_str());
		}
		return str;
	}
}