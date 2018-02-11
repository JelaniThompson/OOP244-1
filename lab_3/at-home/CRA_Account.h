// OOP244-BTP200 Workshop 3: Classes and Privacy
// CRA_Account.h
// Version 2.0
// 2017/09/09
// Chris Szalwinski

#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H

namespace sict {

	const int max_name_length = 40; // max number of character in a name
	const int min_sin = 100000000;  // minimum social insurance number
	const int max_sin = 999999999;  // maximum social insurance number
	const int max_yrs = 4;          // maximum number of taxation years        

	class CRA_Account {
		char m_familyName[max_name_length + 1];
		char m_givenName[max_name_length + 1];
		int  m_sin;
		//* An array of size max_yrs to hold the tax return years.
		int  m_year[max_yrs];

		//* An array of size max_yrs to hold the balance owed or refund due on the account for each tax return year.
		double m_balance[max_yrs];

		//* The number of years for which tax return data is stored
		int  n_years;
	public:
		void set(const char*, const char*, int);
		void set(int, double);
		void display() const;
		bool isEmpty() const;
	};
}

#endif

