#ifndef __PET_H
#define __PET_H

#include <iostream>
#include <vector>
#include <map>

enum Type {POSSUM, HORSE, AXOLOTL, PENGUIN, MONKEY};

std::string to_string(Type _type);

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
