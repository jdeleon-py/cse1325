#include "person.h"
#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade) : Person(name, email), grade{grade} {}

void Student::add_parent(Parent& parent)
{
	parents.push_back(&parent);
}

int Student::num_parents()
{
	return parents.size();
}

Parent& Student::parent(int index)
{
	if((index < 0) || (index >= parents.size()))
	{
		throw std::out_of_range("Index out of range!");
	}
	else
	{
		return *parents[index];
	}
}

std::string Student::full_info()
{
	return name + " (" + email + ") grade " + std::to_string(grade) + " parents: ";
}
