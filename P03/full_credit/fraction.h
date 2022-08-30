#ifndef __FRACTION_H
#define __FRACTION_H

#include <iostream>

class Fraction
{
	public:
		Fraction(int num = 0, int den = 1);

		Fraction operator-();
		Fraction operator+(Fraction& rhs);
		Fraction operator-(Fraction& rhs);
		Fraction operator*(Fraction& rhs);
		Fraction operator/(Fraction& rhs);

		friend std::ostream& operator<<(std::ostream& ost, Fraction& m);
		friend std::istream& operator>>(std::istream& ist, Fraction& m);
		friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
	private:
		int _num;
		int _den;

		void reduce();
};

int gcd(int a, int b);

#endif