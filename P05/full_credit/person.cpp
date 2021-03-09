#include "person.h"

Person::Person(std::string name, std::string email) : name{name}, email{email} {}

std::string Person::to_string()
{
	return name;
}

std::string Person::full_info()
{
	return name + " (" + email + ") ";
}

std::ostream& operator<<(std::ostream& ost, const Person& person)
{
	ost << person.name;
	return ost;
}
