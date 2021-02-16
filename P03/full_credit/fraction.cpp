#include "fraction.h"

Fraction::Fraction(int num, int den) : _numerator{num = 0}, _denominator{den = 1}
{
	if(_denominator == 0)
	{
		std::cerr << "Denominator is zero!" << std::endl;
	}
	else
	{
		reduce();
	}
}

Fraction Fraction::operator-()
{
	Fraction frac;
	frac._numerator = -_numerator;
	frac._denominator = _denominator;
	return frac;
}

Fraction Fraction::operator+(Fraction& rhs)
{
	Fraction sum;
	sum._numerator = (_numerator * rhs._denominator) + (_denominator * rhs._numerator);
	sum._denominator = _denominator * rhs._denominator;
	sum.reduce();
	return sum;
}

Fraction Fraction::operator-(Fraction& rhs)
{
	Fraction difference;
	difference._numerator = (_numerator * rhs._denominator) - (_denominator * rhs._numerator);
	difference._denominator = _denominator * rhs._denominator;
	difference.reduce();
	return difference;
}

Fraction Fraction::operator*(Fraction& rhs)
{
	Fraction product;
	product._numerator = _numerator * rhs._numerator;
	product._denominator = _denominator * rhs._denominator;
	product.reduce();
	return product;
}

Fraction Fraction::operator/(Fraction& rhs)
{
	Fraction quotient;
	quotient._numerator = _numerator * rhs._denominator;
	quotient._denominator = _denominator * rhs._numerator;
	quotient.reduce();
	return quotient;
}

std::ostream& operator<<(std::ostream& ost, const Fraction& m)
{
	ost << m._numerator;
	if(m._denominator != 1)
	{
		ost << '/' << m._denominator;
	}
	return ost;
}

std::istream& operator>>(std::istream& ist, Fraction& m)
{
	int n, d;
	char c;
	ist >> n >> c >> d;

	if(ist && c == '/')
	{
		m._numerator = n;
		m._denominator = d;
	}
	else
	{
		std::cerr << "ERROR: Invalid Fraction!" << std::endl;
	}

	m.reduce();
	return ist;
}

bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
	if((lhs._numerator == rhs._numerator) && (lhs._denominator == rhs._denominator))
	{
		return false;
	}
	else
	{
		return true;
	}
}

int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

void Fraction::reduce()
{
	int comm_den;

	if(_denominator < 0)
	{
		_numerator = -_numerator;
		_denominator = -_denominator;
	}

	comm_den = gcd(_numerator, _denominator);
	_numerator = _numerator / comm_den;
	_denominator = _denominator / comm_den;
}

