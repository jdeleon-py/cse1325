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

	display = Gtk::manage(new Gtk::Label{"Students", Gtk::ALIGN_CENTER});
	vbox -> add(*display);

	//display = Gtk::manage(new Gtk::Label{show_student_data(), Gtk::ALIGN_CENTER});
	//vbox -> add(*display);

	display = Gtk::manage(new Gtk::Label{"Parents", Gtk::ALIGN_CENTER});
	vbox -> add(*display);

	//display = Gtk::manage(new Gtk::Label{show_parent_data(), Gtk::ALIGN_CENTER});
	//vbox -> add(*display);

	vbox -> show_all();

	on_new_school_click();
	show_student_data();
	show_parent_data();
}

Mainwin::~Mainwin() {}

void Mainwin::on_new_school_click()
{
}

void Mainwin::on_new_student_click()
{
	EntryDialog name_log{*this, "<b><big>Student name?</big></b>", true};
	name_log.run();
	std::string student_name = name_log.get_text();

	EntryDialog email_log{*this, "<b><big>Student email?</big></b>", true};
	email_log.run();
	std::string student_email = email_log.get_text();

	EntryDialog grade_log{*this, "<b><big>Student grade?</big></b>", true};
	grade_log.run();
	int student_grade = std::stoi(grade_log.get_text());

	students.push_back(Student{student_name, student_email, student_grade});
	show_student_data();
}

void Mainwin::on_new_parent_click()
{
	EntryDialog name_log{*this, "<b><big>Parent name?</big></b>", true};
	name_log.run();
	std::string parent_name = name_log.get_text();

	EntryDialog email_log{*this, "<b><big>Parent email?</big></b>", true};
	email_log.run();
	std::string parent_email = email_log.get_text();

	parents.push_back(Parent{parent_name, parent_email});
	show_parent_data();
}

void Mainwin::on_student_parent_click()
{
}

void Mainwin::on_quit_click()
{
	close();
}

void Mainwin::show_student_data()
{
	for(int i = 0; i < students.size(); ++i)
	{
		std::cout << i << ") " << students.at(i).full_info() << std::endl;
	}
}

void Mainwin::show_parent_data()
{
	for(int i = 0; i < parents.size(); ++i)
	{
		std::cout << i << ") " << parents.at(i).full_info() << std::endl;
	}
}
