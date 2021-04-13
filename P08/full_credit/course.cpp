#include "course.h"

Course::Course(Subject subject, int grade) : subject{subject}, grade{grade} {}

Course::Course(std::istream& ist)
{
	//ist >> subject >> grade;
	//ist.ignore(32767, '\n');

	//std::getline(ist, subject);
	//std::getline(ist, grade);
}

void Course::save(std::ostream& ost)
{
	ost << subject << '\n' << std::to_string(grade) << '\n';
}

std::ostream& operator<<(std::ostream& ost, const Course& course)
{
	ost << course.subject << " (" << "grade " << std::to_string(course.grade) << ")";
	return ost;
}
