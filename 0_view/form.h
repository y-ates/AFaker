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


class Form{
 private:
	const char* label_default = "DEFAULT";
	int hbox_border = 5;
	int hbox_border = 0;
	
	GtkWidget *hbox = gtk_hbox_new(FALSE, hbox_border);
	GtkWidget *vbox = gtk_vbox_new(FALSE, vbox_border);
	GtkWidget *label;
	GtkWidget *txtField;
	GtkWidget *checkbox;

 public:
	Form();
	Form(const char *label);
	
	static GtkWidget* get_hbox();
	static GtkWidget* get_vbox();
	static GtkWidget* get_label();
	static GtkWidget* get_txtField();
	static GtkWidget* get_checkbox();
	static GtkWidget* set_hbox();
	static GtkWidget* set_vbox();
	static GtkWidget* set_label();
	static GtkWidget* set_txtField();
	static GtkWidget* set_checkbox();

	static GtkWidget *create_checkbox(const char *label);
	static GtkWidget *create_label(const char *txt_label);
	static GtkWidget *create_txtField();

};

#endif
