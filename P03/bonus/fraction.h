#ifndef __FRACTION_H
#define __FRACTION_H

#include <iostream>

class Fraction
{
	public:
		Fraction(int num = 0, int den = 1);

		Fraction operator-();
		Fraction operator+(const Fraction& rhs);
		Fraction operator-(const Fraction& rhs);
		Fraction operator*(const Fraction& rhs);
		Fraction operator/(const Fraction& rhs);

		inline bool operator==(const Fraction& rhs) {return compare(rhs) ==  0;}
		inline bool operator!=(const Fraction& rhs) {return compare(rhs) !=  0;}
		inline bool operator< (const Fraction& rhs) {return compare(rhs) == -1;}
		inline bool operator<=(const Fraction& rhs) {return compare(rhs) <=  0;}
		inline bool operator> (const Fraction& rhs) {return compare(rhs) ==  1;}
		inline bool operator>=(const Fraction& rhs) {return compare(rhs) >=  0;}

		friend std::ostream& operator<<(std::ostream& ost, Fraction& m);
		friend std::istream& operator>>(std::istream& ist, Fraction& m);
	private:
		int _num;
		int _den;

		void reduce();
		int compare(const Fraction& rhs);
};

int gcd(int a, int b);

#endif