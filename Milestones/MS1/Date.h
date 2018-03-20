// Final Project Milestone 1
//
// Version 1.0
// Date: 3/13/2018
// Author: Lean Junio
// Description
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace AMA
{
	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int YEAR_ERROR = 2;
	const int MON_ERROR = 3;
	const int DAY_ERROR = 4;

	const int min_year = 2000;
	const int max_year = 2030;

	class Date
	{
	private:
		int m_year, m_month, m_day, m_comparator, m_errorState;
		int mdays(int, int) const;
		void errCode(int errorCode);

	public:
		Date();
		Date(int month, int day, int year);
		int errCode() const;
		bool bad() const;
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		istream& read(istream& istr);
		ostream& write(ostream& ostr) const;
	};
		ostream& operator<<(ostream& ostr, Date& s);
		istream& operator>>(istream& istr, Date& k);		
}
#endif