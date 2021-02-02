#include "pet.h"

int main(void)
{
	Pet pet1{"Gorgonszola", 2, POSSUM};
	Pet pet2{"Ferbert", 17, HORSE};
	Pet pet3{"Templeton", 9, AXOLOTL};
	Pet pet4{"Chester", 1, PENGUIN};
	Pet pet5{"Giuseppe", 21, MONKEY};

	std::cout << pet1.to_string() << std::endl;
	std::cout << pet2.to_string() << std::endl;
	std::cout << pet3.to_string() << std::endl;
	std::cout << pet4.to_string() << std::endl;
	std::cout << pet5.to_string() << std::endl;
}
