#ifndef __SUBJECT_H
#define __SUBJECT_H

#include <iostream>
#include <vector>
#include <map>

enum class Subject{READING, WRITING, MATH, SCIENCE, HISTORY, ART};

const std::vector<Subject> subjects_vector
{
	Subject::READING,
	Subject::WRITING,
	Subject::MATH,
	Subject::SCIENCE,
	Subject::HISTORY,
	Subject::ART
};

const std::map<Subject, std::string> subject_to_string
{
	{Subject::READING, "Reading"},
	{Subject::WRITING, "Writing"},
	{Subject::MATH,    "Math"},
	{Subject::SCIENCE, "Science"},
	{Subject::HISTORY, "History"},
	{Subject::ART,     "Art"}
};

std::ostream& operator<<(std::ostream& ost, const Subject& subject);

Subject load_subject(std::istream& ist);

#endif
