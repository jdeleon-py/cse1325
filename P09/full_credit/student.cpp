#include "person.h"
#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade) : Person(name, email), grade{grade} {}

Student::Student() {}

Student::Student(std::istream& ist)
{
	ist >> name >> email >> grade;
	ist.ignore(32767, '\n');
}

void Student::save(std::ostream& ost)
{
	Person::save(ost);
	ost << grade << '\n';
}

void Student::save_aggregates(std::ostream& ost)
{
        ost << email << '\n';
        ost << parents.size() << '\n';
        for(Parent* parent: parents) ost << *parent << '\n';
}

void Student::load_aggregates(std::istream& ist, const std::map<std::string, Parent*>& parents)
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
		throw std::runtime_error{"Aggregate parents too big"};
	}

	while(size--)
	{
		std::getline(ist, email_check);
		if(!ist)
		{
			throw std::runtime_error{"Input stream failed on student aggregate load"};
		}
		add_parent(*parents.at(email));
	}
}

void Student::add_parent(Parent& parent)
{
	for(Parent* p : parents) if(p == &parent) return;
	parents.push_back(&parent);
}

/*
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
		return *(parents.at(index));
	}
}
*/

std::string Student::full_info() const
{
	std::string info = Person::full_info() + " in grade " + std::to_string(grade) + " - Parents: ";
	std::string seperator;
	for(auto p : parents)
	{
		info += seperator + (p -> to_string());
		seperator = ", ";
	}
	return info;
}
