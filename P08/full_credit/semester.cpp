#include "semester.h"

std::string convert_to_string(Semester semester)
{
	switch(semester)
	{
		case Semester::FALL   : return "Fall";
		case Semester::SPRING : return "Spring";
		case Semester::SUMMER : return "Summer";
	}
	return "Unknown";
}

std::ostream& operator<<(std::ostream& ost, const Semester& semester)
{
	ost << convert_to_string(semester);
	return ost;
}

Semester load_semester(std::istream& ist)
{
	std::string s;
	std::getline(ist, s);

	if(s == "Fall")   return Semester::FALL;
	if(s == "Spring") return Semester::SPRING;
	if(s == "Summer") return Semester::SUMMER;
	throw std::runtime_error{std::string{"Invalid semester: " + s}};
}
