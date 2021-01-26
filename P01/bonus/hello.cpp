#include <iostream>

int main(void)
{
	setlocale(LC_ALL, "");
	std::string name;
	std::cout << "What is your name? ";
	std::getline(std::cin, name);

	if (name.size() == 0)
	{
		std::cout << "Hello Anonymous Person!" << std::endl;
	}

	else
	{
		std::cout << "Hello " << name << "!" << std::endl;
	}
}
