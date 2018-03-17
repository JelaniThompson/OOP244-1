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
		bool isNegative(int x) const;
		void display(void) const;
		Fraction operator+(const Fraction& rhs) const; 
	};
}

#endif