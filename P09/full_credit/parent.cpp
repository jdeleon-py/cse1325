#include "person.h"
#include "parent.h"
#include "student.h"

Parent::Parent(std::string name, std::string email) : Person(name, email) {}

Parent::Parent() {}

Parent::Parent(std::istream& ist)
{
	ist >> name >> email;
	ist.ignore(32767, '\n');
}

void Parent::save(std::ostream& ost)
{
	Person::save(ost);
}

void Parent::save_aggregates(std::ostream& ost)
{
	ost << email << '\n';
	ost << students.size() << '\n';
	for(Student* student: students) ost << *student << '\n';
}

void Parent::load_aggregates(std::istream& ist, const std::map<std::string, Student*>& students)
{
	std::string email_check;
	std::getline(ist, email_check);
	if(email != email_check)
	{
		throw std::runtime_error{"load_aggregates: " + email_check + " vs " + email};
	}

	int size;
	ist >> size; ist.ignore(32767, '\n');
	if(size > 100)
	{
		throw std::runtime_error{"Aggregate students too big"};
	}

	while(size--)
	{
		std::getline(ist, email_check);
		if(!ist)
		{
			throw std::runtime_error{"Input stream failed on parent aggregate load"};
		}
		add_student(*students.at(email));
	}
}

void Parent::add_student(Student& student)
{
	for(Student* s : students) if(s == &student) return;
	students.push_back(&student);
}

/*
int Parent::num_students()
{
	return students.size();
}

Student& Parent::student(int index)
{
	if((index < 0) || (index >= students.size()))
	{
		throw std::out_of_range("Index not within range!");
	}
	else
	{
		return *(students.at(index));
	}
}
*/

std::string Parent::full_info() const
{
	std::string info = Person::full_info() + " - Students: ";
	std::string seperator;
	for(auto s : students)
	{
		info += seperator + (s -> to_string());
		seperator = ", ";
	}
	return info;
}
