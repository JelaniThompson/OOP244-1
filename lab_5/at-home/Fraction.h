// Workshop 5: operator overloading
// File:Fraction.h
// Version: 1.0
// Date: 2018/2/21
// Author: Lean Junio

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict
{
	class Fraction {
	private:
		int m_numerator;
		int m_denominator;
	public:
		Fraction(void);
		Fraction(int n, int d);
		int max(void) const;
		int min(void) const;
		void reduce(void);
		int gcd(void) const;
		bool isEmpty(void) const;
		void display(void) const;
		bool isNegative(int x) const;
		bool numeratorAndDenominatorsAreEqual(void) const;
		bool fractionsAreEqual(const Fraction& a, const Fraction& b) const;
		bool isValid(const Fraction& fraction) const;
		Fraction operator+(const Fraction& rhs) const;
        Fraction operator*(const Fraction& rhs) const;
        bool operator==(const Fraction& rhs) const;
        bool operator!=(const Fraction& rhs) const;
		Fraction& operator+=(const Fraction& rhs);        
	};
}

#endif