#include "mainwin.h"

Mainwin::Mainwin()
{
	set_default_size(800, 300);
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

	//SAVE SCHOOL (append to FILE menu)
	Gtk::MenuItem *menuitem_save_school = Gtk::manage(new Gtk::MenuItem("_Save", true));
	menuitem_save_school -> signal_activate().connect([this] {this -> on_save_click();});
	filemenu -> append(*menuitem_save_school);

	//SAVE AS SCHOOL (append to FILE menu)
	Gtk::MenuItem *menuitem_saveas_school = Gtk::manage(new Gtk::MenuItem("_Save As", true));
	menuitem_saveas_school -> signal_activate().connect([this] {this -> on_save_as_click();});
	filemenu -> append(*menuitem_saveas_school);

	//OPEN SCHOOL (append to FILE menu)
	Gtk::MenuItem *menuitem_open_school = Gtk::manage(new Gtk::MenuItem("_Open", true));
	menuitem_open_school -> signal_activate().connect([this] {this -> on_open_click();});
	filemenu -> append(*menuitem_open_school);

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

	//NEW TEACHER (append to INSERT menu)
	Gtk::MenuItem *menuitem_new_teacher = Gtk::manage(new Gtk::MenuItem("_New Teacher", true));
	menuitem_new_teacher -> signal_activate().connect([this] {this -> on_new_teacher_click();});
	insertmenu -> append(*menuitem_new_teacher);

	//NEW COURSE (append to INSERT menu)
	Gtk::MenuItem *menuitem_new_course = Gtk::manage(new Gtk::MenuItem("_New Course", true));
	menuitem_new_course -> signal_activate().connect([this] {this -> on_new_course_click();});
	insertmenu -> append(*menuitem_new_course);

	//NEW SECTION (append to INSERT menu)
	Gtk::MenuItem *menuitem_new_section = Gtk::manage(new Gtk::MenuItem("_New Section", true));
	menuitem_new_section -> signal_activate().connect([this] {this -> on_new_section_click();});
	insertmenu -> append(*menuitem_new_section);

	//NEW TRANSCRIPT (append to INSERT menu)
	Gtk::MenuItem *menuitem_new_transcript = Gtk::manage(new Gtk::MenuItem("_New Transcript", true));
	menuitem_new_transcript -> signal_activate().connect([this] {this -> on_new_transcript_click();});
	insertmenu -> append(*menuitem_new_transcript);

	//NEW GRADE (append to INSERT menu)
	Gtk::MenuItem *menuitem_new_grade = Gtk::manage(new Gtk::MenuItem("_New Grade", true));
	menuitem_new_grade -> signal_activate().connect([this] {this -> on_set_grade_click();});
	insertmenu -> append(*menuitem_new_grade);

	//RELATE (create menu and add to MENU)
	Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
	menubar -> append(*menuitem_relate);
	Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
	menuitem_relate -> set_submenu(*relatemenu);

	//STUDENT TO PARENT (append to RELATE menu)
	Gtk::MenuItem *menuitem_student_parent = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
	menuitem_student_parent -> signal_activate().connect([this] {this -> on_student_parent_click();});
	relatemenu -> append(*menuitem_student_parent);

	//VIEW (create menu and add to MENU)
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
	menubar -> append(*menuitem_view);
	Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view -> set_submenu(*viewmenu);

	//VIEW STUDENTS (append to VIEW menu)
	Gtk::MenuItem *menuitem_view_students = Gtk::manage(new Gtk::MenuItem("_View Students", true));
	menuitem_view_students -> signal_activate().connect([this] {this -> show_data(View::STUDENTS);});
	viewmenu -> append(*menuitem_view_students);

	//VIEW PARENTS (append to VIEW menu)
	Gtk::MenuItem *menuitem_view_parents = Gtk::manage(new Gtk::MenuItem("_View Parents", true));
	menuitem_view_parents -> signal_activate().connect([this] {this -> show_data(View::PARENTS);});
	viewmenu -> append(*menuitem_view_parents);

	//VIEW TEACHERS (append to VIEW menu)
	Gtk::MenuItem *menuitem_view_teachers = Gtk::manage(new Gtk::MenuItem("_View Teachers", true));
	menuitem_view_teachers -> signal_activate().connect([this] {this -> show_data(View::TEACHERS);});
	viewmenu -> append(*menuitem_view_teachers);

	//VIEW COURSES (append to VIEW menu)
	Gtk::MenuItem *menuitem_view_courses = Gtk::manage(new Gtk::MenuItem("_View Courses", true));
	menuitem_view_courses -> signal_activate().connect([this] {this -> show_data(View::COURSES);});
	viewmenu -> append(*menuitem_view_courses);

	//VIEW SECTIONS (append to VIEW menu)
	Gtk::MenuItem *menuitem_view_sections = Gtk::manage(new Gtk::MenuItem("_View Sections", true));
	menuitem_view_sections -> signal_activate().connect([this] {this -> show_data(View::SECTIONS);});
	viewmenu -> append(*menuitem_view_sections);

	//VIEW TRANSCRIPTS (append to VIEW menu)
	Gtk::MenuItem *menuitem_view_transcripts = Gtk::manage(new Gtk::MenuItem("_View Transcripts", true));
	menuitem_view_transcripts -> signal_activate().connect([this] {this -> show_data(View::TRANSCRIPTS);});
	viewmenu -> append(*menuitem_view_transcripts);

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

	Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
	toolbar -> append(*sep1);

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

	//NEW TEACHER (TOOLBAR)
	Gtk::Image* button_teacher_image = Gtk::manage(new Gtk::Image{"teacher.png"});
	Gtk::ToolButton *teacher_button = Gtk::manage(new Gtk::ToolButton(*button_teacher_image));
	teacher_button -> set_tooltip_markup("Add a new teacher");
	teacher_button -> signal_clicked().connect([this] {this -> on_new_teacher_click();});
	toolbar -> append(*teacher_button);

	Gtk::SeparatorToolItem *sep2 = Gtk::manage(new Gtk::SeparatorToolItem());
	toolbar -> append(*sep2);

	//NEW COURSE (TOOLBAR)
	Gtk::Image* button_course_image = Gtk::manage(new Gtk::Image{"course.png"});
	Gtk::ToolButton *course_button = Gtk::manage(new Gtk::ToolButton(*button_course_image));
	course_button -> set_tooltip_markup("Add a new course");
	course_button -> signal_clicked().connect([this] {this -> on_new_course_click();});
	toolbar -> append(*course_button);

	//NEW SECTION (TOOLBAR)
	Gtk::Image* button_section_image = Gtk::manage(new Gtk::Image{"section.png"});
	Gtk::ToolButton *section_button = Gtk::manage(new Gtk::ToolButton(*button_section_image));
	section_button -> set_tooltip_markup("Add a new section");
	section_button -> signal_clicked().connect([this] {this -> on_new_section_click();});
	toolbar -> append(*section_button);

	//NEW TRANSCRIPT (TOOLBAR)
	Gtk::Image* button_transcript_image = Gtk::manage(new Gtk::Image{"transcript.png"});
	Gtk::ToolButton *transcript_button = Gtk::manage(new Gtk::ToolButton(*button_transcript_image));
	transcript_button -> set_tooltip_markup("Add a new transcript");
	transcript_button -> signal_clicked().connect([this] {this -> on_new_transcript_click();});
	toolbar -> append(*transcript_button);

	//NEW GRADE (TOOLBAR)
	Gtk::Image* button_grade_image = Gtk::manage(new Gtk::Image{"grade.png"});
	Gtk::ToolButton *grade_button = Gtk::manage(new Gtk::ToolButton(*button_grade_image));
	grade_button -> set_tooltip_markup("Set a new grade");
	grade_button -> signal_clicked().connect([this] {this -> on_set_grade_click();});
	toolbar -> append(*grade_button);

	display = Gtk::manage(new Gtk::Label());
	display -> set_hexpand(true);
	display -> set_vexpand(true);
	vbox -> add(*display);

	vbox -> show_all();

	on_new_school_click();
}

Mainwin::~Mainwin()
{
	for(Student* s: students)       delete s;
	for(Parent* p: parents)         delete p;
	for(Course* c: courses)         delete c;
	for(Section* s: sections)       delete s;
	for(Teacher* t: teachers)       delete t;
	for(Transcript* t: transcripts) delete t;
}

void Mainwin::on_new_school_click()
{
	for(Student* s: students)       delete s;
	for(Parent* p: parents)         delete p;
	for(Course* c: courses)         delete c;
	for(Section* s: sections)       delete s;
	for(Teacher* t: teachers)       delete t;
	for(Transcript* t: transcripts) delete t;
	students.clear();
	parents.clear();
	courses.clear();
	sections.clear();
	teachers.clear();
	transcripts.clear();
	filename = DEFAULT_FILENAME;
	show_data(View::STUDENTS);
}

void Mainwin::on_save_click()
{
	try
	{
		std::ofstream ofs{filename};

		ofs << FILE_VERSION << '\n';

		ofs << students.size() << '\n';
		for(Student* student: students) student -> save(ofs);
		ofs << parents.size() << '\n';
		for(Parent* parent: parents) parent -> save(ofs);

		for(Student* student: students) student -> save_aggregates(ofs);
		for(Parent* parent: parents) parent -> save_aggregates(ofs);

		ofs << courses.size() << '\n';
		for(Course* course: courses) course -> save(ofs);
		ofs << sections.size() << '\n';
		for(Section* section: sections) section -> save(ofs);
		ofs << teachers.size() << '\n';
		for(Teacher* teacher : teachers) teacher -> save(ofs);
		ofs << transcripts.size() << '\n';
		for(Transcript* transcript : transcripts) transcript -> save(ofs);

		if(!ofs) throw std::runtime_error{"Error writing file"};
	}
	catch(std::exception& e)
	{
		Gtk::MessageDialog{*this, "Unable to save school"}.run();
	}
}

void Mainwin::on_save_as_click()
{
	Gtk::FileChooserDialog dialog("Please choose a file",
		Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
	dialog.set_transient_for(*this);

	auto filter_smart = Gtk::FileFilter::create();
	filter_smart -> set_name("SMART files");
	filter_smart -> add_pattern(FILE_PATTERN);
	dialog.add_filter(filter_smart);

	auto filter_any = Gtk::FileFilter::create();
	filter_any -> set_name("Any files");
	filter_any -> add_pattern("*");
	dialog.add_filter(filter_any);

	dialog.set_filename(filename);

	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("_Save", Gtk::RESPONSE_OK);

	int result = dialog.run();

	if(result == Gtk::RESPONSE_OK)
	{
		filename = dialog.get_filename();
		on_save_click();
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

	dialog.set_filename(filename);

	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("_Open", Gtk::RESPONSE_OK);

	int result = dialog.run();

	if(result == Gtk::RESPONSE_OK)
	{
		try
		{
			std::ifstream ifs{dialog.get_filename()};

			on_new_school_click();
			show_data(View::STUDENTS);
			filename = dialog.get_filename();

			int size;
			ifs >> size; ifs.ignore(32767, '\n');
			while(size--) students.push_back(new Student{ifs});

			ifs >> size; ifs.ignore(32767, '\n');
			while(size--) parents.push_back(new Parent{ifs});

			std::ostringstream oss;
			std::map<std::string, Parent*> parent_aggregates;
			for(Parent* p: parents)
			{
				oss.str("");
				oss << *p;
				parent_aggregates[oss.str()] = p;
			}
			for(Student* s: students) s -> load_aggregates(ifs, parent_aggregates);

			std::map<std::string, Student*> student_aggregates;
			for(Student* s: students)
			{
				oss.str("");
				oss << *s;
				student_aggregates[oss.str()] = s;
			}
			for(Parent* p: parents) p -> load_aggregates(ifs, student_aggregates);

			ifs >> size; ifs.ignore(32767, '\n');
			while(size--) courses.push_back(new Course{ifs});

			ifs >> size; ifs.ignore(32767, '\n');
			while(size--) sections.push_back(new Section{ifs});

			ifs >> size; ifs.ignore(32767, '\n');
			while(size--) teachers.push_back(new Teacher{ifs});

			ifs >> size; ifs.ignore(32767, '\n');
			while(size--) transcripts.push_back(new Transcript{ifs});

			if(!ifs) throw std::runtime_error{"File contents bad"};
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
		if(name_log.run() == Gtk::RESPONSE_OK) name_log.hide();
		else return;

		EntryDialog email_log{*this, "<b><big>Student email?</big></b>", true};
		if(email_log.run() == Gtk::RESPONSE_OK) email_log.hide();
		else return;

		EntryDialog grade_log{*this, "<b><big>Student grade?</big></b>", true};
		grade_log.run();
		int student_grade = std::stoi(grade_log.get_text());

		if(student_grade < 1) return;

		students.push_back(new Student{name_log.get_text(), email_log.get_text(), student_grade});
	}
	catch(std::exception& e)
	{
		Gtk::MessageDialog{*this, "Invalid entry!" + std::string{e.what()}}.run();
	}
	show_data(View::STUDENTS);
}

void Mainwin::on_new_parent_click()
{
	try
	{
		EntryDialog name_log{*this, "<b><big>Parent name?</big></b>", true};
		if(name_log.run() == Gtk::RESPONSE_OK) name_log.hide();
		else return;

		EntryDialog email_log{*this, "<b><big>Parent email?</big></b>", true};
		if(email_log.run() == Gtk::RESPONSE_OK) email_log.hide();
		else return;

		parents.push_back(new Parent{name_log.get_text(), email_log.get_text()});
	}
	catch(std::exception& e)
	{
		Gtk::MessageDialog{*this, e.what()}.run();
	}
	show_data(View::PARENTS);
}

void Mainwin::on_new_teacher_click()
{
	try
	{
		EntryDialog name_log{*this, "<b><big>Teacher name?</big></b>", true};
		if(name_log.run() == Gtk::RESPONSE_OK) name_log.hide();
		else return;

		EntryDialog email_log{*this, "<b><big>Teacher email?</big></b>", true};
		if(email_log.run() == Gtk::RESPONSE_OK) email_log.hide();
		else return;

		teachers.push_back(new Teacher{name_log.get_text(), email_log.get_text()});
	}
	catch(std::exception& e)
	{
		Gtk::MessageDialog{*this, e.what()}.run();
	}
	show_data(View::TEACHERS);
}

void Mainwin::on_student_parent_click()
{
	try
	{
		int student = select_student();
		if(student < 0) return;

		int parent = select_parent();
		if(parent < 0) return;

		students.at(student) -> add_parent(*parents.at(parent));
		parents.at(parent) -> add_student(*students.at(student));
	}
	catch(std::exception& e)
	{
		Gtk::MessageDialog{*this, e.what()}.run();
	}
	show_data(View::STUDENTS);
}

void Mainwin::on_new_course_click()
{
	try
	{
		std::string s = "Subject name?\n\n";
		for(int i = 0; i < subjects_vector.size(); ++i)
		{
			s += std::to_string(i) + ") " + subject_to_string.at(subjects_vector[i]) + '\n';
		}

		EntryDialog ds{*this, s};
		if(ds.run() == Gtk::RESPONSE_OK) ds.hide();
		else return;

		Subject subject = subjects_vector.at(std::stoi(ds.get_text()));

		EntryDialog grade{*this, "Grade (1-12)?"};
		if(grade.run() == Gtk::RESPONSE_OK) grade.hide();
		else return;

		courses.push_back(new Course{subject, std::stoi(grade.get_text())});
	}
	catch(std::exception& e)
	{
		Gtk::MessageDialog{*this, e.what()}.run();
	}
	show_data(View::COURSES);
}

void Mainwin::on_new_section_click()
{
	try
	{
		Gtk::Dialog d{"Course", *this};
		auto vbox = d.get_content_area();

		ComboBoxContainer<std::vector<Course*>> cbt_courses(courses, courses.size() - 1);
		vbox -> pack_start(cbt_courses);

		ComboBoxContainer<std::vector<Teacher*>> cbt_teachers(teachers, teachers.size() - 1);
		vbox -> pack_start(cbt_teachers);

		Gtk::HBox hbox;
		Gtk::Label l_year("Year:");
		Gtk::SpinButton sb_year;
		sb_year.set_range(2020, 2100);
		sb_year.set_increments(1, 25);
		hbox.pack_start(l_year);
		hbox.pack_start(sb_year);
		vbox -> pack_start(hbox);

		d.add_button("Cancel", 0);
		d.add_button("Fall", 1);
		d.add_button("Spring", 2);
		d.add_button("Summer", 3);
		d.show_all();

		int r = d.run();
		if(!r) return;
		Course& course = *courses.at(cbt_courses.get_active_row_number());
		Teacher& teacher = *teachers.at(cbt_teachers.get_active_row_number());
		Semester semester = (r == 1) ? Semester::FALL : ((r == 2) ? Semester::SPRING : Semester::SUMMER);

		int year = sb_year.get_value();

		sections.push_back(new Section{course, semester, year, teacher});
	}
	catch(std::exception& e)
	{
		Gtk::MessageDialog{*this, e.what()}.run();
	}
	show_data(View::SECTIONS);
}

void Mainwin::on_new_transcript_click()
{
	Gtk::Dialog d{"Create Transcript", *this};
	auto vbox = d.get_content_area();

	ComboBoxContainer<std::vector<Student*>> cbt_students(students, students.size() - 1);
	vbox -> pack_start(cbt_students);

	ComboBoxContainer<std::vector<Section*>> cbt_sections(sections, sections.size() - 1);
	vbox -> pack_start(cbt_sections);

	d.add_button("Cancel", 0);
	d.add_button("Create", 1);

	d.show_all();
	if(d.run() != 1) return;

	Student& student = *students.at(cbt_students.get_active_row_number());
	Section& section = *sections.at(cbt_sections.get_active_row_number());

	show_data(View::TRANSCRIPTS);
}

void Mainwin::on_set_grade_click()
{
	Gtk::Dialog d{"Assign Grade", *this};
	auto vbox = d.get_content_area();

	ComboBoxContainer<std::vector<Transcript*>> cbt_transcripts(transcripts, transcripts.size() - 1);
	vbox -> pack_start(cbt_transcripts);

	d.add_button("Cancel", -1);
	int index = 0;
	for(Grade grade : grades_vector) d.add_button(grade_to_string.at(grade), index++);

	d.show_all();
	try
	{
		int result = d.run();
		if(result < 0 || result >= grades_vector.size()) return;

		Transcript& transcript = *transcripts.at(cbt_transcripts.get_active_row_number());
		transcript.assign_grade(grades_vector.at(result));
	}
	catch(std::exception& e)
	{
		Gtk::MessageDialog{*this, "Invalid transcript selected"}.run();
	}
	show_data(View::TRANSCRIPTS);
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

void Mainwin::show_data(View view)
{
	static View current_view;
	if(view != View::SAME) current_view = view;

	std::ostringstream oss;

	if(current_view == View::STUDENTS)
	{
		oss << "   <b><big>Students</big></b>\n\n";
		for(int i = 0; i < students.size(); ++i)
		{
			oss << students.at(i) -> full_info() << '\n';
		}
	}
	else if(current_view == View::PARENTS)
	{
		oss << "   <b><big>Parents</big></b>\n\n";
		for(int i = 0; i < parents.size(); ++i)
		{
			oss << parents.at(i) -> full_info() << '\n';
		}
	}
	else if(current_view == View::TEACHERS)
	{
		oss << "   <b><big>Teachers</big></b>\n\n";
		for(int i = 0; i < teachers.size(); ++i)
		{
			oss << teachers.at(i) -> full_info() << '\n';
		}
	}
	else if(current_view == View::COURSES)
	{
		oss << "   <b><big>Courses</big></b>\n\n";
		for(auto course: courses)
		{
			oss << *course << '\n';
		}
	}
	else if(current_view == View::SECTIONS)
	{
		oss << "   <b><big>Sections</big></b>\n\n";
		for(auto section: sections)
		{
			oss << *section << '\n';
		}
	}
	else if(current_view == View::TRANSCRIPTS)
	{
		oss << "   <b><big>Transcripts</big></b>\n\n";
		for(auto transcript: transcripts)
		{
			oss << *transcript << '\n';
		}
	}
	else
	{
		current_view = View::STUDENTS;
	}

	display -> set_markup(oss.str());
}

int Mainwin::select_student()
{
	std::string prompt = "Select Student\n\n";
	for(int i = 0; i < students.size(); ++i)
	{
		prompt += std::to_string(i) + ") " + students[i] -> to_string() + '\n';
	}
	return select(prompt, students.size() - 1);
}

int Mainwin::select_parent()
{
	std::string prompt = "Select Parent\n\n";
	for(int i = 0; i < parents.size(); ++i)
	{
		prompt += std::to_string(i) + ") " + parents[i] -> to_string() + '\n';
	}
	return select(prompt, parents.size() - 1);
}
/*
int Mainwin::select_teacher()
{
	std::string prompt = "Select Teacher\n\n";
	for(int i = 0; i < teachers.size(); ++i)
	{
		prompt += std::to_string(i) + ") " + teachers[i] -> to_string() + '\n';
	}
	return select(prompt, teachers.size() - 1);
}
*/
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
				if(min <= selection && selection <= max) break;
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
