#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>

class Person
{
public:
	Person(std::string name, std::string email);
	Person();
	Person(std::istream& ist);
	std::string to_string() const;
	virtual void save(std::ostream& ost);
	virtual std::string full_info() const;
	friend std::ostream& operator<<(std::ostream& ost, const Person& person);
protected:
	std::string name;
	std::string email;
};

#endif
