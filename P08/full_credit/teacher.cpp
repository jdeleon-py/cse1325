#include "person.h"
#include "teacher.h"

Teacher::Teacher(std::string name, std::string email) : Person(name, email) {}

Teacher::Teacher(std::istream& ist)
{
	ist >> name >> email;
	ist.ignore(32767, '\n');
}

void Teacher::save(std::ostream& ost)
{
	Person::save(ost);
}

std::string Teacher::full_info() const
{
	return Person::full_info();
}
