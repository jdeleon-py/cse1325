#include "fraction.h"

int main(void)
{
	Fraction frac1, frac2;

	std::cout << "Enter two fractions: <n/d n/d>" << std::endl;
	std::cin >> frac1 >> frac2;

	std::cout << "Fraction #1: " << frac1 << std::endl;
	std::cout << "Fraction #2: " << frac2 << std::endl;

	Fraction frac1_neg = -frac1;
	Fraction frac2_neg = -frac2;
	std::cout << "Negation of Fraction #1: " << frac1_neg << std::endl;
	std::cout << "Negation of Fraction #2: " << frac2_neg << std::endl;

	Fraction frac_add = frac1 + frac2;
	std::cout << "Addition: " << frac_add << std::endl;

	Fraction frac_subtract = frac1 - frac2;
	std::cout << "Subtraction: " << frac_subtract << std::endl;

	Fraction frac_mult = frac1 * frac2;
	std::cout << "Multiplication: " << frac_mult << std::endl;

	Fraction frac_div = frac1 / frac2;
	std::cout << "Division : " << frac_div << std::endl;
}