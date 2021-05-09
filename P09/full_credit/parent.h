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
	//int num_students();
	//Student& student(int index);
	std::string full_info() const override;

	//Create an iterator to iterate over a parent to get their students
	typedef std::vector<Student*>::iterator iterator;
	typedef std::vector<Student*>::const_iterator const_iterator;
	inline iterator begin() {return students.begin();}
	inline iterator end() {return students.end();}
protected:
	std::vector<Student*> students;
};

#endif
