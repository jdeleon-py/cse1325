#ifndef __SECTION_H
#define __SECTION_H

#include <iostream>
#include "course.h"
#include "semester.h"
#include "teacher.h"

class Section
{
public:
	Section(Course course, Semester semester, int year, Teacher teacher);
	Section();
	Section(std::istream& ist);
	void save(std::ostream& ost);
	friend std::ostream& operator<<(std::ostream& ost, const Section& section);
private:
	Course _course;
	Semester _semester;
	Teacher _teacher;
	int _year;
	int _max_students;
};

#endif
