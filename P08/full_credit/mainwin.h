#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <fstream>
#include <gtkmm.h>
#include "parent.h"
#include "student.h"
#include "course.h"
#include "section.h"

const std::string EXTENSION = "smart";
const std::string FILE_PATTERN = "*." + EXTENSION;
const std::string DEFAULT_FILENAME = "untitled." + EXTENSION;
const std::string FILE_VERSION = "0.1";

class Mainwin : public Gtk::Window
{
public:
	Mainwin();
	virtual ~Mainwin();
protected:
	void on_new_school_click();
	void on_save_click();
	void on_save_as_click();
	void on_open_click();
	void on_new_student_click();
	void on_new_parent_click();
	void on_student_parent_click();
	void on_new_course_click();
	void on_new_section_click();
	void on_about_click();
	void on_quit_click();
private:
	void show_student_data();
	void show_parent_data();
	void show_course_data();
	void show_section_data();
	int select_student();
	int select_parent();
	int select_subject();
	int select(std::string prompt, int max = INT_MAX, int min = 0);

	Gtk::Label *display;
	std::string filename;
	std::vector<Student*> students;
	std::vector<Parent*> parents;
	std::vector<Course*> courses;
	std::vector<Section*> sections;
};

#endif
