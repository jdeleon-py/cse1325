#ifndef __SEMESTER_H
#define __SEMESTER_H

#include <iostream>

enum class Semester{FALL, SPRING, SUMMER};

std::string convert_to_string(Semester semester);

std::ostream& operator<<(std::ostream& ost, const Semester& semester);

void load_semester(std::istream& ist);

#endif

