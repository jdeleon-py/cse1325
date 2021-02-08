#include "pet.h"

std::string to_str(Type _type)
{
	std::vector<std::string> vec = {"Possum", "Horse", "Axolotl", "Penguin", "Monkey"};
	return vec[_type];
}

Pet::Pet(std::string name, double age, Type type) : _name{name}, _age{age}, _type{type} {}

double Pet::human_years()
{
	return _age * human_lifespan / pet_lifespan[_type];
}

std::string Pet::output()
{
	return _name + " is a " + to_str(_type) + " age " + std::to_string(_age) + " or " + std::to_string(human_years()) + " in human-equivalent years.";
}
