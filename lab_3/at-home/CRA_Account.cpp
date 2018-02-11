// OOP244-BTP200 Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 2.1
// 2018/01/23
// Chris Szalwinski

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
	// set stores a family name, given name and SIN, validating first,
	// in the current object
	//
	void CRA_Account::set(const char* fn, const char* gn, int sin_) {
		// assume sin is invalid, then check if valid
		m_familyName[0] = '\0';
		m_givenName[0] = '\0';
		m_sin = 0;

		int sin = sin_;

		//* if sin is valid and familyname and given names are not empty
		if (sin >= min_sin && sin <= max_sin && fn[0] != '\0' && gn[0] != '\0') {

			// let sum = 0
			int sum = 0;

			for (int i = 0; i < 5; ++i)
			{
				int temp = sin % 100;
				int even = temp / 10 * 2;
				sum += temp % 10 + even / 10 + even % 10;
				sin /= 100;
			}
			if (sum % 10 == 0) {
				m_sin = sin_;
				strncpy(m_familyName, fn, max_name_length + 1);
				m_familyName[max_name_length] = '\0';
				strncpy(m_givenName, gn, max_name_length + 1);
				m_givenName[max_name_length] = '\0';
			}
		}
		for (int i = 0; i < max_yrs; ++i)
			m_balance[i] = 0;
		n_years = 0;
	}

	// set adds a year and balanace to the return records for the
	// current object
	void CRA_Account::set(int year, double balance)
	{
		if (!isEmpty() && n_years < max_yrs) {
			m_year[n_years] = year;
			m_balance[n_years] = balance;
			n_years++;
		}
	}

	// display inserts the current object's data into the output stream
	//
	void CRA_Account::display() const
	{
		if (!isEmpty()) {
			cout << "Family Name: " << m_familyName << endl;
			cout << "Given Name : " << m_givenName << endl;
			cout << "CRA Account: " << m_sin << endl;
			cout << fixed << setprecision(2);
			for (int i = 0; i < n_years; ++i) {
				cout << "Year (" << m_year[i] << ") ";
				if (m_balance[i] > 2.00) {
					cout << "balance owing: " << m_balance[i] << endl;
				}
				else if (m_balance[i] < -2.00) {
					cout << "refund due: " << -m_balance[i] << endl;
				}
				else {
					cout << "No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	// isEmpty returns the empty status of the current object
	//
	bool CRA_Account::isEmpty() const
	{
		return !m_sin;
	}
}



