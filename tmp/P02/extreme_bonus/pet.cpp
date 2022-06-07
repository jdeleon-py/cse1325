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

bool compare_age(Pet p1, Pet p2) {return p1.human_years() > p2.human_years();}