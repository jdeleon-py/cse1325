#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>
#include <vector>
#include "person.h"

class Parent;

class Student : public Person
{
public:
	Student(std::string name, std::string email, int grade);
	Student();
	Student(std::istream& ist);
	virtual void save(std::ostream& ost);
	void add_parent(Parent& parent);
	int num_parents();
	Parent& parent(int index);
	std::string full_info() const override;
protected:
	int grade;
	std::vector<Parent*> parents;
};

#endif

