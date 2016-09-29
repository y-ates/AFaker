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

#include "form.h"


Form::Form(){
	
}

Form::Form(const char *label){
	
}

GtkWidget* Form::get_hbox(){
	return hbox;
}

GtkWidget* Form::get_vbox(){
	return vbox;
}
	
GtkWidget* Form::get_label(){
	return label;
}

GtkWidget* Form::get_txtField(){
	return txtField;
}

GtkWidget* Form::get_checkbox(){
	return checkbox;
}

void Form::set_label(GtkWidget* label_widget){
	/*
	 * TODO:
	 * Validate label
	 */
	//gtk_label_set_text(GTK_LABEL(label), label_text);
	label = label_widget;
}

void Form::set_txtField(GtkWidget* txtField_widget){
	/*
	 * TODO:
	 * Validate text
	 */
	//gtk_entry_set_text(GTK_ENTRY(txtField), text);
	txtField = txtField_widget;
}

void Form::set_checkbox(GtkWidget* checkbox_widget){
	/*
	 * TODO:
	 * Validate text
	 */
	checkbox = checkbox_widget;
}

void Form::set_vbox(GtkWidget* vbox_widget){
	vbox = vbox_widget;
}

void Form::set_hbox(GtkWidget* hbox_widget){
	hbox = hbox_widget;
}

GtkWidget* Form::create_checkbox(const char* label){
	GtkWidget *cbox;

	cbox = gtk_check_button_new_with_label(label);

	// g_signal_connect(GTK_WIDGET(cbox), "toggled",
	// 		 G_CALLBACK(GUI::chkbox_listen), cbox);

	return cbox;
}

GtkWidget* Form::create_label(const char *txt_label){
	GtkWidget *label = gtk_label_new(txt_label);

	gtk_label_set_text(GTK_LABEL(label), txt_label);
	gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);

	return label;
}

GtkWidget* Form::create_txtField(){
	GtkWidget *tField = gtk_entry_new();

	return tField;
}
