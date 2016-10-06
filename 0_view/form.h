/******************************************************************************
 ** Copyright (C) 2016 Yakup Ates <Yakup.Ates@rub.de>

 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** any later version.

 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.

 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/

#ifndef _FORM_H
#define _FORM_H

#include <gtk/gtk.h>
#include <iostream>

class Form{
 private:
	const char* label_default = "DEFAULT";
        static const int hbox_border = 5;
	static const int vbox_border = 0;
	
	GtkWidget* hbox = gtk_hbox_new(FALSE, 5);
	GtkWidget* vbox = gtk_vbox_new(FALSE, 0);
	GtkWidget* label;
	GtkWidget* txtField;
	GtkWidget* checkbox;
	
 public:
	Form();
	Form(const char *label);
	
	GtkWidget* get_hbox();
	GtkWidget* get_vbox();
	GtkWidget* get_label();
	GtkWidget* get_txtField();
	GtkWidget* get_checkbox();
	void set_label(GtkWidget* label_widget);
	void set_txtField(GtkWidget* txtField_widget);
	void set_checkbox(GtkWidget* checkbox_widget);
	void set_hbox(GtkWidget* hbox_widget);
	void set_vbox(GtkWidget* vbox_widget);
        void chkbox_on();
	void chkbox_off();
	void chkbox_listen(GtkWidget *cbox);
	void activate_txtField();
	void deactivate_txtField();
 
	GtkWidget* create_checkbox(const char* label);
	GtkWidget* create_label(const char* txt_label);
	GtkWidget* create_txtField();

};

#endif
