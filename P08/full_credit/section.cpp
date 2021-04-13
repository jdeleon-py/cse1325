#include "section.h"

Section::Section(Course course, Semester semester, int year) : course{course}, semester{semester}, year{year} {}

Section::Section(std::istream& ist)
{
	//ist >> course >> semester >> year;
	//ist.ignore(32767, '\n');

	//std::getline(ist, course);
	//std::getline(ist, semester);
	//std::getline(ist, year);
}

void Section::save(std::ostream& ost)
{
	ost << course << '\n' << semester << '\n' << std::to_string(year) << '\n';
}

std::ostream& operator<<(std::ostream& ost, const Section& section)
{
	ost << section.course << " for " << section.semester << " " << std::to_string(section.year);
	return ost;
}
