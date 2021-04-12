#include "person.h"

Person::Person(std::string name, std::string email) : name{name}, email{email} {}

Person::Person() {}

Person::Person(std::istream& ist)
{
	std::getline(ist, name);
	std::getline(ist, email);
}

void Person::save(std::ostream& ost)
{
	ost << name << '\n' << email << '\n';
}

std::string Person::to_string() const
{
	return name;
}

std::string Person::full_info() const
{
	return name + " (" + email + ") ";
}

std::ostream& operator<<(std::ostream& ost, const Person& person)
{
	ost << person.to_string();
	return ost;
}
