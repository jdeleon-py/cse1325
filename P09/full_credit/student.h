#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>
#include <vector>
#include <map>
#include "person.h"

class Parent;

class Student : public Person
{
public:
	Student(std::string name, std::string email, int grade);
	Student();
	Student(std::istream& ist);
	void save(std::ostream& ost) override;
	void save_aggregates(std::ostream& ost);
	void load_aggregates(std::istream& ist, const std::map<std::string, Parent*>& parents);
	void add_parent(Parent& parent);
	//int num_parents();
	//Parent& parent(int index);
	std::string full_info() const override;

	//Create an iterator to iterate over a student to get their parents
	typedef std::vector<Parent*>::iterator iterator;
	typedef std::vector<Parent*>::const_iterator const_iterator;
	iterator begin() {return parents.begin();}
	iterator end() {return parents.end();}
protected:
	int grade;
	std::vector<Parent*> parents;
};

#endif

