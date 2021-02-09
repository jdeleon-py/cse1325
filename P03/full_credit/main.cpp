#include "fraction.h"

int main(void)
{
	Fraction frac1;
	Fraction frac2;
	Fraction new_frac;

	std::cout << "Enter fraction #1 <n/d>: ";
	std::cin >> frac1;

	std::cout << "Enter fraction #2 <n/d>: ";
	std::cin >> frac2;

	new_frac = frac1 + frac2;
	std::cout << "Sum: " << new_frac << std::endl;

	new_frac = frac1 - frac2;
	std::cout << "Difference: " << new_frac << std::endl;

	new_frac = frac1 * frac2;
	std::cout << "Product: " << new_frac << std::endl;

	new_frac = frac1 / frac2;
	std::cout << "Quotient: " << new_frac << std::endl;
}
