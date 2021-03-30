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

	//HELP (create menu and add to MENU)
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
	menubar -> append(*menuitem_help);
	Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
	menuitem_help -> set_submenu(*helpmenu);

	//ABOUT (append to HELP menu)
	Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
	menuitem_about -> signal_activate().connect([this] {this -> on_about_click();});
	helpmenu -> append(*menuitem_about);

	//TOOLBAR (create toolbar)
	Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
	vbox -> pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

	//NEW SCHOOL (TOOLBAR)
	Gtk::ToolButton *new_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
	new_school_button -> set_tooltip_markup("Create a new school, discarding any progress");
	new_school_button -> signal_clicked().connect([this] {this -> on_new_school_click();});
	toolbar -> append(*new_school_button);

	//OPEN SCHOOL (TOOLBAR)
	Gtk::ToolButton *open_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
	open_school_button -> set_tooltip_markup("Open an existing school's data");
	open_school_button -> signal_clicked().connect([this] {this -> on_open_click();});
	toolbar -> append(*open_school_button);

	//SAVE SCHOOL (TOOLBAR)
	Gtk::ToolButton *save_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
	save_school_button -> set_tooltip_markup("Save an existing school's data");
	save_school_button -> signal_clicked().connect([this] {this -> on_save_click();});
	toolbar -> append(*save_school_button);

	//SAVE AS SCHOOL (TOOLBAR)
	Gtk::ToolButton *save_as_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
	save_as_school_button -> set_tooltip_markup("Save as an existing school's data");
	save_as_school_button -> signal_clicked().connect([this] {this -> on_save_as_click();});
	toolbar -> append(*save_as_school_button);

	//NEW STUDENT (TOOLBAR)
	Gtk::Image* button_student_image = Gtk::manage(new Gtk::Image{"student.png"});
	Gtk::ToolButton *new_student_button = Gtk::manage(new Gtk::ToolButton(*button_student_image));
	new_student_button -> set_tooltip_markup("Add a new student");
	new_student_button -> signal_clicked().connect([this] {this -> on_new_student_click();});
	toolbar -> append(*new_student_button);

	//NEW PARENT (TOOLBAR)
	Gtk::Image* button_parent_image = Gtk::manage(new Gtk::Image{"parent.png"});
	Gtk::ToolButton *new_parent_button = Gtk::manage(new Gtk::ToolButton(*button_parent_image));
	new_parent_button -> set_tooltip_markup("Add a new parent");
	new_parent_button -> signal_clicked().connect([this] {this -> on_new_parent_click();});
	toolbar -> append(*new_parent_button);

	//RELATE (TOOLBAR)
	Gtk::Image* button_relate_image = Gtk::manage(new Gtk::Image{"relate.png"});
	Gtk::ToolButton *relate_button = Gtk::manage(new Gtk::ToolButton(*button_relate_image));
	relate_button -> set_tooltip_markup("Relate a student to a parent");
	relate_button -> signal_clicked().connect([this] {this -> on_student_parent_click();});
	toolbar -> append(*relate_button);

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

void Mainwin::on_save_click()
{
	on_save_as_click();
}

void Mainwin::on_save_as_click()
{
	Gtk::FileChooserDialog dialog("Please choose a file",
		Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
	dialog.set_transient_for(*this);

	auto filter_smart = Gtk::FileFilter::create();
	filter_smart -> set_name("SMART files");
	filter_smart -> add_pattern("*.smart");
	dialog.add_filter(filter_smart);

	auto filter_any = Gtk::FileFilter::create();
	filter_any -> set_name("Any files");
	filter_any -> add_pattern("*");
	dialog.add_filter(filter_any);

	dialog.set_filename("untitled.smart");

	dialog.add_button("_Cancel", 0);
	dialog.add_button("_Save", 1);

	int result = dialog.run();

	if(result == 1)
	{
		try
		{
			std::ofstream ofs{dialog.get_filename()};
			ofs << std::to_string(students.size()) << std::endl;
			for(auto s : students)
			{
				s.save(ofs);
			}
			ofs << std::to_string(parents.size()) << std::endl;
			for(auto p : parents)
			{
				p.save(ofs);
			}
		}
		catch(std::exception& e)
		{
			Gtk::MessageDialog{*this, "Unable to save data"}.run();
		}
	}
}

void Mainwin::on_open_click()
{
	Gtk::FileChooserDialog dialog("Please choose a file",
		Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	auto filter_smart = Gtk::FileFilter::create();
	filter_smart -> set_name("SMART files");
	filter_smart -> add_pattern("*.smart");
	dialog.add_filter(filter_smart);

	auto filter_any = Gtk::FileFilter::create();
	filter_any -> set_name("Any files");
	filter_any -> add_pattern("*");
	dialog.add_filter(filter_any);

	dialog.set_filename("untitled.smart");

	dialog.add_button("_Cancel", 0);
	dialog.add_button("_Open", 1);

	int result = dialog.run();

	if(result == 1)
	{
		try
		{
			on_new_school_click();
			show_data();
			std::ifstream ifs{dialog.get_filename()};
			std::string s, s_size, p_size;
			int i = 0;
			int j = 0;

			if(!ifs)
			{
				throw std::runtime_error{"File contents bad"};
			}

			std::getline(ifs, s_size);
			while(i < stoi(s_size))
			{
				std::getline(ifs, s);
				students.push_back(Student{ifs});
				++i;
			}
			//std::getline(ifs, p_size);
			//while(j < stoi(p_size))
			//{
			//	std::getline(ifs, s);
			//	parents.push_back(Parent{ifs});
			//	++j;
			//}
			show_data();
		}
		catch(std::exception& e)
		{
			Gtk::MessageDialog{*this, "Unable to open data"}.run();
		}
	}
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

void Mainwin::on_about_click()
{
	Gtk::AboutDialog dialog;
	dialog.set_transient_for(*this);
	dialog.set_program_name("SMART");
	auto logo = Gdk::Pixbuf::create_from_file("about.png");
	dialog.set_logo(logo);
	dialog.set_version("Version 1.7.0");
	dialog.set_copyright("Copyright 2021");
	dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
	std::vector<Glib::ustring> authors = {"James A. deLeon"};
	dialog.set_authors(authors);
	std::vector <Glib::ustring> artists = {"Logo designed by James A. deLeon, licensed under Program Inc."};
	dialog.set_artists(artists);
	dialog.run();
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
