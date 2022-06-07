#include "pet.h"

int main(void)
{
	std::vector<Pet> pets
	{
		Pet{"Beau", 4, DOG},
		Pet{"P. Diddly", 2, OPPOSSUM},
		Pet{"Gort", 7, CAPYBARA}
	};

	for(Pet p: pets) {std::cout << p.to_string() << std::endl;}
}