#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <iostream>
#include <vector>
#include <string>
#include <gtkmm.h>
#include "parent.h"
#include "student.h"

class Mainwin : public Gtk::Window
{
public:
	Mainwin();
	virtual ~Mainwin();
protected:
	void on_new_school_click();
	void on_new_student_click();
	void on_new_parent_click();
	void on_student_parent_click();
	void on_quit_click();
private:
	void show_student_data();
	void show_parent_data();

	Gtk::Label *display;
	std::vector<Student> students;
	std::vector<Parent> parents;
};

#endif
