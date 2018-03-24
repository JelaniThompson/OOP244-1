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
		Date(int year, int month, int day);
		int errCode(void) const;
		bool bad(void) const;
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};
		std::ostream& operator<<(std::ostream& ostr, Date&);
		std::istream& operator>>(std::istream& istr, Date&);		
}
#endif