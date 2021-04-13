#include "subject.h"

std::string convert_to_string(Subject subject)
{
	switch(subject)
	{
		case Subject::READING : return "Reading";
		case Subject::WRITING : return "Writing";
		case Subject::MATH    : return "Math";
		case Subject::SCIENCE : return "Science";
		case Subject::ART     : return "Art";
	}
	return "Unknown";
}

std::ostream& operator<<(std::ostream& ost, const Subject& subject)
{
	ost << convert_to_string(subject);
	return ost;
}

void load_subject(std::istream& ist)
{}

