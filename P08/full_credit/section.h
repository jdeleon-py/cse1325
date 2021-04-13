#ifndef __SECTION_H
#define __SECTION_H

#include <iostream>
#include "course.h"
#include "semester.h"

class Section
{
public:
	Section(Course course, Semester semester, int year);
	Section();
	Section(std::istream& ist);
	void save(std::ostream& ost);
	friend std::ostream& operator<<(std::ostream& ost, const Section& section);
private:
	Course course;
	Semester semester;
	int year;
};

#endif
