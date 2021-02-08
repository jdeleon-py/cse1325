#include "pet.h"

int main(void)
{
	std::vector<Pet> pets
	{
		Pet{"Gorgonszola", 2, POSSUM},
		Pet{"Ferbert", 17, HORSE},
		Pet{"Templeton", 9, AXOLOTL},
		Pet{"Chester", 1, PENGUIN},
		Pet{"Giuseppe", 21, MONKEY}
	};

	for(Pet p : pets) std::cout << p.output() << std::endl;
}
