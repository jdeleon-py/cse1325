#ifndef __TRANSCRIPT_H
#define __TRANSCRIPT_H

#include <iostream>
#include "section.h"
#include "student.h"
#include "grade.h"

class Transcript
{
public:
	Transcript(Student student, Section section);
	Transcript();
	Transcript(std::istream& ist);
	void save(std::ostream& ost);
	void assign_grade(Grade grade);
	friend std::ostream& operator<<(std::ostream& ost, const Transcript& transcript);
private:
	Section _section;
	Student _student;
	Grade _grade;
};

#endif
