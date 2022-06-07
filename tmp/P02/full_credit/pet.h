#ifndef __PET_H
#define __PET_H

#include <iostream>
#include <vector>

enum Type {DOG, OPPOSSUM, CAPYBARA};

class Pet
{
	public:
		Pet(std::string name, double age, Type type);
		std::string to_string();

	private:
		std::string _name;
		double _age;
		Type _type;
};

#endif