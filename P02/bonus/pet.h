#ifndef __PET_H
#define __PET_H

#include <iostream>
#include <vector>
#include <string>

enum Type {POSSUM, HORSE, AXOLOTL, PENGUIN, MONKEY};
const double human_lifespan = 80.0;
const std::vector<double> pet_lifespan {4.0, 30.0, 15.0, 20.0, 32.0};

std::string to_str(Type _type);

class Pet
{
public:
	Pet(std::string name, double age, Type type);
	std::string output();
	double human_years();
private:
	std::string _name;
	double _age;
	Type _type;
};

#endif
