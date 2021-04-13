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

void load_semester(std::istream& ist)
{}
