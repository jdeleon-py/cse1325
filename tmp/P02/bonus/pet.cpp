#include "pet.h"

Pet::Pet(std::string name, double age, Type type) : _name{name}, _age{age}, _type{type} {}

std::string Pet::to_string()
{
	std::vector<std::string> vec = {"Dog", "Oppossum", "Capybara"};
	return _name + " is a " + vec[_type] + " age " + std::to_string(_age) + " or " + std::to_string(human_years()) + " in human-equivalent years.";
}

double Pet::human_years()
{
	std::vector<double> lifespan = {15.0, 4.0, 12.0};
	return (_age * human_lifespan) / lifespan[_type];
}