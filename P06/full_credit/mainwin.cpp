#include "mainwin.h"
#include "entrydialog.h"

Mainwin::Mainwin()
{
	set_default_size(400, 200);
	set_title("SMART");

	Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
	add(*vbox);

	//MENU
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
	vbox -> pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	//FILE (create menu and add to MENU)
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar -> append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file -> set_submenu(*filemenu);

	//NEW SCHOOL (append to FILE menu)
	Gtk::MenuItem *menuitem_new_school = Gtk::manage(new Gtk::MenuItem("_New School", true));
	menuitem_new_school -> signal_activate().connect([this] {this -> on_new_school_click();});
	filemenu -> append(*menuitem_new_school);

	//QUIT (append to FILE Menu)
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit -> signal_activate().connect([this] {this -> on_quit_click();});
	filemenu -> append(*menuitem_quit);

	//INSERT (create menu and add to MENU)
	Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
	menubar -> append(*menuitem_insert);
	Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
	menuitem_insert -> set_submenu(*insertmenu);

	//NEW STUDENT (append to INSERT menu)
	Gtk::MenuItem *menuitem_new_student = Gtk::manage(new Gtk::MenuItem("_New Student", true));
	menuitem_new_student -> signal_activate().connect([this] {this -> on_new_student_click();});
	insertmenu -> append(*menuitem_new_student);

	//NEW PARENT (append to INSERT menu)
	Gtk::MenuItem *menuitem_new_parent = Gtk::manage(new Gtk::MenuItem("_New Parent", true));
	menuitem_new_parent -> signal_activate().connect([this] {this -> on_new_parent_click();});
	insertmenu -> append(*menuitem_new_parent);

	//RELATE (create menu and add to MENU)
	Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
	menubar -> append(*menuitem_relate);
	Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
	menuitem_relate -> set_submenu(*relatemenu);

	//STUDENT TO PARENT (append to RELATE menu)
	Gtk::MenuItem *menuitem_student_parent = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
	menuitem_student_parent -> signal_activate().connect([this] {this -> on_student_parent_click();});
	relatemenu -> append(*menuitem_student_parent);

	display = Gtk::manage(new Gtk::Label());
	display -> set_hexpand(true);
	display -> set_vexpand(true);
	vbox -> add(*display);

	vbox -> show_all();

	on_new_school_click();
}

Mainwin::~Mainwin() {}

void Mainwin::on_new_school_click()
{
	students.clear();
	parents.clear();
	show_data();
}

void Mainwin::on_new_student_click()
{
	try
	{
		EntryDialog name_log{*this, "<b><big>Student name?</big></b>", true};
		if(name_log.run() == Gtk::RESPONSE_OK)
		{
			name_log.hide();
		}
		else
		{
			return;
		}

		EntryDialog email_log{*this, "<b><big>Student email?</big></b>", true};
		if(email_log.run() == Gtk::RESPONSE_OK)
		{
			email_log.hide();
		}
		else
		{
			return;
		}

		EntryDialog grade_log{*this, "<b><big>Student grade?</big></b>", true};
		grade_log.run();
		int student_grade = std::stoi(grade_log.get_text());

		if(student_grade < 1)
		{
			return;
		}

		students.push_back(Student{name_log.get_text(), email_log.get_text(), student_grade});
	}
	catch(std::exception& e)
	{
		Gtk::MessageDialog{*this, "Invalid entry!" + std::string{e.what()}}.run();
	}
	show_data();
}

void Mainwin::on_new_parent_click()
{
	try
	{
		EntryDialog name_log{*this, "<b><big>Parent name?</big></b>", true};
		if(name_log.run() == Gtk::RESPONSE_OK)
		{
			name_log.hide();
		}
		else
		{
			return;
		}

		EntryDialog email_log{*this, "<b><big>Parent email?</big></b>", true};
		if(email_log.run() == Gtk::RESPONSE_OK)
		{
			email_log.hide();
		}
		else
		{
			return;
		}

		parents.push_back(Parent{name_log.get_text(), email_log.get_text()});
	}
	catch(std::exception& e)
	{
		Gtk::MessageDialog{*this, e.what()}.run();
	}
	show_data();
}

void Mainwin::on_student_parent_click()
{
	try
	{
		int student = select_student();
		if(student < 0)
		{
			return;
		}

		int parent = select_parent();
		if(parent < 0)
		{
			return;
		}

		students.at(student).add_parent(parents.at(parent));
		parents.at(parent).add_student(students.at(student));
	}
	catch(std::exception& e)
	{
		Gtk::MessageDialog{*this, e.what()}.run();
	}
	show_data();
}

void Mainwin::on_quit_click()
{
	close();
}

void Mainwin::show_data()
{
	std::string s;
	s += "    Students\n\n";

	for(int i = 0; i < students.size(); ++i)
	{
		s += students.at(i).full_info() + '\n';
	}

	s += "    Parents\n\n";

	for(int i = 0; i < parents.size(); ++i)
	{
		s += parents.at(i).full_info() + '\n';
	}

	display -> set_markup(s);
}

int Mainwin::select_student()
{
	std::string prompt = "Select Student\n\n";
	for(int i = 0; i < students.size(); ++i)
	{
		prompt += std::to_string(i) + ") " + students[i].to_string() + '\n';
	}
	return select(prompt, students.size() - 1);
}

int Mainwin::select_parent()
{
	std::string prompt = "Select Parent\n\n";
	for(int i = 0; i < parents.size(); ++i)
	{
		prompt += std::to_string(i) + ") " + parents[i].to_string() + '\n';
	}
	return select(prompt, parents.size() - 1);
}

int Mainwin::select(std::string prompt, int max, int min)
{
	int selection = min - 1;
	while(true)
	{
		try
		{
			EntryDialog dialog{*this, prompt};
			int response = dialog.run();
			if(response == Gtk::RESPONSE_OK)
			{
				selection = std::stoi(dialog.get_text());
				if(min <= selection && selection <= max)
				{
					break;
				}
				throw std::out_of_range{"Invalid selection"};
			}
			else
			{
				selection = min - 1;
				break;
			}
		}
		catch(std::exception& e)
		{
			Gtk::MessageDialog{*this, e.what()}.run();
		}
	}
	return selection;
}
