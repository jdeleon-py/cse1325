#ifndef __FRACTION_H
#define __FRACTION_H

#include <iostream>
#include <vector>
#include <sstream>

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
	int _numerator;
	int _denominator;
	void reduce();
};

std::ostream& operator<<(std::ostream& ost, Fraction& m);

std::istream& operator>>(std::istream& ist, Fraction& m);

bool operator!=(const Fraction& lhs, const Fraction& rhs);

int gcd(int a, int b);

#endif
