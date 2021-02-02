#include "pet.h"

std::string to_str(Type _type)
{
	std::vector<std::string> vec = {"Possum", "Horse", "Axolotl", "Penguin", "Monkey"};
	return vec[_type];
}

Pet::Pet(std::string name, double age, Type type) : _name{name}, _age{age}, _type{type} {}

std::string Pet::to_string()
{
	return _name + " is a " + to_str(_type) + " age " + std::to_string(_age);
}
