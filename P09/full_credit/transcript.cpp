#include "transcript.h"

Transcript::Transcript(Student student, Section section) : _student{student}, _section{section} {}

Transcript::Transcript(std::istream& ist) : _section{ist} {}

void Transcript::save(std::ostream& ost) {}

void Transcript::assign_grade(Grade grade)
{
	_grade = grade;
}

std::ostream& operator<<(std::ostream& ost, const Transcript& transcript)
{
	ost << "In " << transcript._section << ": " << transcript._student << " earned a: ";// << transcript._grade;
	return ost;
}
