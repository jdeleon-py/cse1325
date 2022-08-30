#include "fraction.h"

Fraction::Fraction(int num, int den) : _num{num}, _den{den}
{
	if(_den == 0) {std::cerr << "Denominator is zero!" << std::endl;}
	else {reduce();}
}

Fraction Fraction::operator-() {return Fraction{-_num, _den};}

Fraction Fraction::operator+(const Fraction& rhs)
{
	Fraction sum;
	sum._num = (_num * rhs._den) + (_den * rhs._num);
	sum._den = _den * rhs._den;
	sum.reduce();
	return sum;
}

Fraction Fraction::operator-(const Fraction& rhs)
{
	Fraction difference;
	difference._num = (_num * rhs._den) - (_den * rhs._num);
	difference._den = _den * rhs._den;
	difference.reduce();
	return difference;
}

Fraction Fraction::operator*(const Fraction& rhs)
{
	Fraction product;
	product._num = _num * rhs._num;
	product._den = _den * rhs._den;
	product.reduce();
	return product;
}

Fraction Fraction::operator/(const Fraction& rhs)
{
	Fraction quotient;
	quotient._num = _num * rhs._den;
	quotient._den = _den * rhs._num;
	quotient.reduce();
	return quotient;
}

void Fraction::reduce()
{
	int common_den = gcd(_num, _den);
	_num = _num / common_den;
	_den = _den / common_den;
	if (_den < 0)
	{
		_num = -_num;
		_den = -_den;
	}
}

int Fraction::compare(const Fraction& rhs)
{
	int left = _num * rhs._den;
	int right = _den * rhs._num;
	if(left > right) {return 1;}
	else if (left < right) {return -1;}
	else {return 0;}
}

int gcd(int a, int b)
{
	if(b == 0) {return a;}
	else {return gcd(b, a % b);}
}

std::ostream& operator<<(std::ostream& ost, Fraction& m)
{
	if(m._den == 1) {ost << m._num;}
	else {ost << m._num << "/" << m._den;}
	return ost;
}

std::istream& operator>>(std::istream& ist, Fraction& m)
{
	int n, d;
	char c;
	ist >> n >> c >> d;
	if(c != '/') {std::cerr << "Invalid Fraction!" << std::endl;}
	else
	{
		m._num = n;
		m._den = d;
	}
	m.reduce();
	return ist;
}