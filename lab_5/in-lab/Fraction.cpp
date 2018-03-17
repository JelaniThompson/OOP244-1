#include <iostream>
#include <algorithm>
#include <numeric>
#include "Fraction.h"
using namespace std;

namespace sict
{
	Fraction::Fraction(void)
	{
		m_numerator = 0;
		m_denominator = 0;
	}
	Fraction::Fraction(int n, int d)
	{
		bool valid = n >= 0 && d > 0;

		if (valid)
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
		return std::max(m_numerator, m_denominator);
	}
	int Fraction::min(void) const
	{
		return std::min(m_numerator, m_denominator);
	}
	void Fraction::reduce(void)
	{
		int greatestCommonDivisor = gcd();

		m_numerator /= greatestCommonDivisor;
		m_denominator /= greatestCommonDivisor;
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
		if (isEmpty())
		{
			cout << "no fraction stored";
		}
		else if (m_denominator == 1)
		{
			cout << m_numerator;
		}
		else
		{
			cout << m_numerator << "/" << m_denominator;
		}
	}
	Fraction Fraction::operator+(const Fraction& rhs) const
	{
		Fraction temp(1, -1);
		if (isEmpty() == false && rhs.isEmpty() == false){
			temp.m_numerator = ((m_numerator*rhs.m_denominator) + (rhs.m_numerator*m_denominator));
			temp.m_denominator =(m_denominator*rhs.m_denominator);
		}
		return temp;
	} 
}