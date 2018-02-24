// Workshop 5: operator overloading
// File:Fraction.cpp
// Version: 1.0
// Date: 2018/2/21
// Author: Lean Junio

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
		return (m_numerator == 0 && m_denominator == 0);
	}

	bool Fraction::isValid(const Fraction& fraction) const
	{
		bool validFraction = fraction.m_numerator >= 0 && fraction.m_denominator > 0;
		return validFraction;
	}

	bool Fraction::isNegative(int x) const
	{
		return (x < 0);
	}

	bool Fraction::fractionsAreEqual(const Fraction& a, const Fraction& b) const
	{
		bool numeratorsEqual = a.m_numerator == b.m_numerator;
		bool denominatorsEqual = a.m_denominator == b.m_denominator;
		return numeratorsEqual && denominatorsEqual;
	}

	bool Fraction::numeratorAndDenominatorsAreEqual(void) const
	{
		return m_numerator == m_denominator;
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
		if (isEmpty() == false && rhs.isEmpty() == false)
		{
			temp.m_numerator = ((m_numerator*rhs.m_denominator) + (rhs.m_numerator*m_denominator));
			temp.m_denominator =(m_denominator*rhs.m_denominator);
		}
		return temp;
	}

	Fraction Fraction::operator*(const Fraction& rhs) const
	{
		Fraction temp;
		bool valid = isValid(*this) && isValid(rhs);
		if(valid)
		{	
			temp.m_numerator = this->m_numerator * rhs.m_numerator;
			temp.m_denominator = this->m_denominator * rhs.m_denominator;			
			return temp;
		}
		else
		{
			temp = Fraction();
			return temp;
		}
	}

	bool Fraction::operator==(const Fraction& rhs) const
	{
		bool validFractions = isValid(*this) && isValid(rhs);
		bool equalFractions = fractionsAreEqual(*this, rhs);
		return validFractions && equalFractions;
	}

	bool Fraction::operator!=(const Fraction& rhs) const
	{
		bool validFractions = isValid(*this) && isValid(rhs);
		bool inEqualFractions = fractionsAreEqual(*this, rhs) == false;
		return validFractions && inEqualFractions;
	}

	Fraction& Fraction::operator+=(const Fraction& rhs) const
	{
		bool validFractions = isValid(*this) && isValid(rhs);
		Fraction temp;
		Fraction& tmp = temp;
		tmp = *this + rhs;
		return tmp;
	}
}
