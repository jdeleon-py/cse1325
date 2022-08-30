#ifndef __PET_H
#define __PET_H

#include <iostream>
#include <vector>
#include <algorithm>

enum Type {DOG, OPPOSSUM, CAPYBARA};
const double human_lifespan = 80;

class Pet
{
	public:
		Pet(std::string name, double age, Type type);
		std::string to_string();
		double human_years();

	private:
		std::string _name;
		double _age;
		Type _type;
};

bool compare_age(Pet p1, Pet p2);

#endif