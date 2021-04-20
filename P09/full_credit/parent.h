#ifndef __PARENT_H
#define __PARENT_H

#include <iostream>
#include <vector>
#include <map>
#include "person.h"

class Student;

class Parent : public Person
{
public:
	Parent(std::string name, std::string email);
	Parent();
	Parent(std::istream& ist);
	void save(std::ostream& ost) override;
	void save_aggregates(std::ostream& ost);
	void load_aggregates(std::istream& ist, const std::map<std::string, Student*>& students);
	void add_student(Student& student);
	int num_students();
	Student& student(int index);
	std::string full_info() const override;
protected:
	std::vector<Student*> students;
};

#endif
