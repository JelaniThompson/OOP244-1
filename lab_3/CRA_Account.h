// OOP244-BTP200 Workshop 3: Classes and Privacy
// CRA_Account.h
// Version 2.0
// 2017/09/09
// Chris Szalwinski

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {

	const int max_name_length = 40; // max number of character in a name
	const int min_sin = 100000000;  // minimum social insurance number
	const int max_sin = 999999999;  // maximum social insurance number

	class CRA_Account {
		char m_familyName[max_name_length + 1];
		char m_givenName[max_name_length + 1];
		int  m_sin;
	public:
		void set(const char*, const char*, int);
		void display() const;
		bool isEmpty() const;
	};
}

#endif

