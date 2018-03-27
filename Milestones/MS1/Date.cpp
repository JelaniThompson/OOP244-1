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
#include <iostream>
#include<iomanip>
#include "Date.h"
using namespace std;

namespace AMA
{
	// Set the attributes to a safe empty state
	Date::Date()
	{
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_comparator = 0;
		m_errorState = 0;
	}

	// Checks if the date is valid and saves the data if it is
	Date::Date(int year, int month, int day)
	{
		bool yearValid = (year >= min_year || year <= max_year) && year > 0;
		int daysInMonth = mdays(month, year);
		bool daysInMonthValid = daysInMonth != 13 && day <= daysInMonth;

		if (yearValid && daysInMonthValid)
		{
			m_year = year;
			m_month = month;
			m_day = day;
			m_errorState = NO_ERROR;
			m_comparator = year * 372 + month * 13 + day;			
		}
		else
		{
			*this = Date();
			m_errorState = NO_ERROR;
		}
	}
	
	// Sets the error state variable to one of the values listed
	void Date::errCode(int errorCode)
	{
		m_errorState = errorCode;
	}
	// Return the error state as an error code value
	int Date::errCode() const
	{
		return m_errorState;
	}

	// Retun true if m_errorState != NO_ERROR
	bool Date::bad() const
	{
		return m_errorState == NO_ERROR;
	}


	// compare if rhs == this
	bool Date::operator==(const Date& rhs) const
	{
		bool day = this->m_day == rhs.m_day;
		bool month = this->m_month == rhs.m_month;
		bool year = this->m_year == rhs.m_year;
		
		return (day && month && year);
	}

	// compare if rhs != this
	bool Date::operator!=(const Date& rhs) const
	{
		return !(*this == rhs);
	}

	// check if this < rhs
	bool Date::operator<(const Date& rhs) const
	{
		bool lessYear = this->m_year < rhs.m_year;
		bool lessMonth = this->m_month < rhs.m_month;
		bool lessDay = this->m_day < rhs.m_day;

		if (lessYear)
		{
			return true;
		}
		else if (lessMonth)
		{
			return true;
		}
		else if (lessDay)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// check if this > rhs
	bool Date::operator>(const Date& rhs) const
	{
		return !(*this < rhs);
	}

	// Check if this <= rhs
	bool Date::operator<=(const Date& rhs) const
	{
		return *this < rhs || *this == rhs;
	}

	// Check if this >= rhs
	bool Date::operator>=(const Date& rhs) const
	{
		return *this > rhs || *this == rhs;		
	}

	// works with an istream object to read a date from the console
	std::istream& Date::read(std::istream& istr)
	{
		char symbol;
		istr.clear();
		istr >> m_year >> symbol >> m_month >> symbol >> m_day;

		if (istr.fail())
		{
			*this = Date();
			errCode(CIN_FAILED);
		}
		else if (min_year > m_year || m_year > max_year)
		{
			*this = Date();
			errCode(YEAR_ERROR);
		}
		else if (1 > m_month || m_month > 12)
		{
			*this = Date();
			errCode(MON_ERROR);
		}
		else if (m_day > mdays(m_month, m_year))
		{
			*this = Date();
			errCode(DAY_ERROR);
		}

		//istr.clear();
		return istr;
	}

	// Works with an ostream object to print a date to the console
	std::ostream& Date::write(std::ostream& ostr) const
	{
		char symbol = '/';
		// For year
		ostr << m_year << symbol;

		// If the m_month < 10, add a zero before the month
		if (m_month < 10)
		{
			ostr << 0;
		}

		// In all cases, add the month
		ostr << m_month << symbol;

		if (m_day < 10)
		{
			ostr << 0;
		}

		ostr << m_day;

		// Return the output stream that was created
		return ostr;
	}

	// Returns the number of days in month of year
	int Date::mdays(int mon, int year) const
	{
		int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	std::istream& operator>>(std::istream& istr, Date& s)
	{
		return s.read(istr);
	}

	std::ostream& operator<<(std::ostream& ostr, Date& k)
	{
		return k.write(ostr);
	}
}
