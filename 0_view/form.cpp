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
	// const char* label_name = "test_label";
	
	// label = create_label(label_name);
	// txtField = create_txtField();
	// checkbox = create_checkbox(label_name);
}

Form::Form(const char *label_name){
	// label = create_label(label_name);
	// txtField = create_txtField();
	// checkbox = create_checkbox(label_name);
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
	checkbox = cbox;

	/*
	 * Callback function has to be static. Some problems here. FixIt.
	 */
	//g_signal_connect(GTK_WIDGET(cbox), "toggled",
	//		 G_CALLBACK(chkbox_listen), cbox);
	
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

void Form::chkbox_on(){
	//std::cout << "on" << std::endl;
	activate_txtField();
	/*
	 * TODO:
	 * User wants to edit form field manually. Set textfield
	 * editable and get value when "send" button is clicked
	 */
}

void Form::chkbox_off(){
	//std::cout << "off" << std::endl;
	deactivate_txtField();
	/*
	 * TODO:
	 * Checkbox is off per default. That means that the form is
	 * filled automatically with dynamically generated data.
	 */
}

void Form::chkbox_listen(GtkWidget *cbox){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cbox)))
		chkbox_on();
	else
		chkbox_off();
}

void Form::deactivate_txtField(){
	gtk_editable_set_editable(GTK_EDITABLE(txtField), FALSE);
	gtk_widget_set_can_focus(GTK_WIDGET(txtField), FALSE);

	const GdkColor GREY = {0, 48000, 48000, 48000};
	gtk_widget_modify_base(txtField, GTK_STATE_NORMAL, &GREY);

	//gtk_entry_set_text(GTK_ENTRY(tField), "TEST");
}

void Form::activate_txtField(){
	gtk_editable_set_editable(GTK_EDITABLE(txtField), TRUE);
	gtk_widget_set_can_focus(GTK_WIDGET(txtField), TRUE);

	const GdkColor WHITE = {0, 65535, 65535, 65535};
	gtk_widget_modify_base(txtField, GTK_STATE_NORMAL, &WHITE);
}
