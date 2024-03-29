#ifndef __COMBOBOXCONTAINER_H
#define __COMBOBOXCONTAINER_H

#include <sstream>
#include <iostream>
#include <gtkmm.h>

template <class T>
class ComboBoxContainer : public Gtk::ComboBoxText
{
public:
	ComboBoxContainer(const T& container, int set_active = 0)
	{
		std::ostringstream oss;
		for(auto e : container)
		{
			oss.str("");
			oss << *e;
			append(oss.str());
		}
	}
};

#endif
