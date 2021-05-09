#ifndef __TEACHER_H
#define __TEACHER_H

#include <iostream>
#include <vector>
#include <sstream>
#include "person.h"

class Section;

class Teacher : public Person
{
public:
	using Person::Person;
	Teacher(std::istream& ist);
	void save(std::ostream& ost) override;
	std::string full_info() const override;
};

#endif
