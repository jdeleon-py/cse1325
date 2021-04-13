#ifndef __SUBJECT_H
#define __SUBJECT_H

#include <iostream>

enum class Subject{READING, WRITING, MATH, SCIENCE, HISTORY, ART};

std::string convert_to_string(Subject subject);

std::ostream& operator<<(std::ostream& ost, const Subject& subject);

void load_subject(std::istream& ist);

#endif
