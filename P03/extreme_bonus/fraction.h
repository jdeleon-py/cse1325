#ifndef __FRACTION_H
#define __FRACTION_H

#include <iostream>

class Fraction
{
	public:
		Fraction(int num = 0, int den = 1);

		// Arithmetic Operation Overloads (Fraction <-> Fraction)
		Fraction operator-();
		Fraction operator+(const Fraction& rhs);
		Fraction operator-(const Fraction& rhs);
		Fraction operator*(const Fraction& rhs);
		Fraction operator/(const Fraction& rhs);

		Fraction operator+=(const Fraction& rhs);
		Fraction operator-=(const Fraction& rhs);
		Fraction operator*=(const Fraction& rhs);
		Fraction operator/=(const Fraction& rhs);

		// Arithmetic Operation Overloads (Fraction <-> int)
		Fraction operator+(const int& num);
		Fraction operator-(const int& num);
		Fraction operator*(const int& num);
		Fraction operator/(const int& num);

		Fraction operator+=(const int& rhs);
		Fraction operator-=(const int& rhs);
		Fraction operator*=(const int& rhs);
		Fraction operator/=(const int& rhs);

		// Comparison Operation Overloads
		inline bool operator==(const Fraction& rhs) {return compare(rhs) ==  0;}
		inline bool operator!=(const Fraction& rhs) {return compare(rhs) !=  0;}
		inline bool operator< (const Fraction& rhs) {return compare(rhs) == -1;}
		inline bool operator<=(const Fraction& rhs) {return compare(rhs) <=  0;}
		inline bool operator> (const Fraction& rhs) {return compare(rhs) ==  1;}
		inline bool operator>=(const Fraction& rhs) {return compare(rhs) >=  0;}

		// I/O Operation Overloads
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