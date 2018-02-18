#include <iostream>
#include <algorithm>
#include <numeric>
#include "Fraction.h"
using namespace std;

namespace sict
{
	Fraction::Fraction(void)
	{
		// Set object to empty state
		m_numerator = 0;
		m_denominator = 0;
	}
	Fraction::Fraction(int n, int d)
	{
		// receive numerator and denominator
		// validate data - numerator: not-negative, denominator: positive value
		// if invalid, set to empty state

		if (!isNegative(n) && !isNegative(d))
		{
			m_numerator = n;
			m_denominator = d;
			reduce();
		}
		else
		{
			*this = Fraction();
		}
	}
	int Fraction::max(void) const
	{
		// returns the greater number between the numerator and the denominator
		return std::max(m_numerator, m_denominator);
	}
	int Fraction::min(void) const
	{
		// returns the lesser number between the numerator and the denominator
		return std::min(m_numerator, m_denominator);
	}
	void Fraction::reduce(void)
	{
		if (m_numerator != m_denominator)
		{
			m_numerator /= gcd();
			m_denominator = m_denominator/gcd();
		}
		else
		{
			m_numerator = 1;
			m_denominator = 1;
		}
	}
	int Fraction::gcd(void) const
	{
		return std::__gcd(m_numerator, m_denominator);
	}
	bool Fraction::isEmpty(void) const
	{
		// if SES, return true
		return (m_numerator == 0 and m_denominator == 0);
	}
	bool Fraction::isNegative(int x) const
	{
		// return 0 if x is negative
		return (x < 0);
	}
	void Fraction::display(void) const
	{
		// DEFAULT output: NUMERATOR/DENOMINATOR
		// return only NUMERATOR if denominator is 1
		// if SES, return "no fraction stored"
		
		if (isEmpty())
		{
			cout << "no fraction stored" << endl;
		}
		else if (m_denominator == 1)
		{
			cout << m_numerator << endl;
		}
		else
		{
			cout << m_numerator << "/" << m_denominator << endl;
		}
		
	}
	// Fraction::Fraction operator+(const Fraction& rhs) const
	// {
	// 	// *this - left hand side
	// 	// rhs - right hand side
	// 	// if not empty, return added fraction that is reduced
	// 	// if SES, return empty fraction object
	// } 
}