#include "person.h"
#include "teacher.h"

//Teacher::Teacher(std::string name, std::string email) : Person(name, email) {}

Teacher::Teacher(std::istream& ist) : Person{ist} {}

void Teacher::save(std::ostream& ost)
{
	Person::save(ost);
}

std::string Teacher::full_info() const
{
	std::ostringstream oss;
	oss << Person::full_info();
	return oss.str();
}
