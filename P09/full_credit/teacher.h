#ifndef __TEACHER_H
#define __TEACHER_H

#include <iostream>
#include <vector>
#include "person.h"

class Teacher : public Person
{
public:
	Teacher(std::string name, std::string email);
	Teacher();
	Teacher(std::istream& ist);
	void save(std::ostream& ost) override;
	std::string full_info() const override;
};

#endif
