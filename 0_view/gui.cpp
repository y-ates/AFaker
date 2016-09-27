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

// #include <gtk/gtk.h>
// #include <iostream>
// #include <string>
// #include <vector>
#include "gui.h"

//using namespace std;

		
void GUI::but_send(GtkWidget *widget, gpointer data){
	g_print("Sending...\r\n");

	/*
	 * TODO:
	 * Get value of all forms and call send function.
	 */
}

void GUI::but_clicked(GtkWidget *widget, GtkWidget *txtField){
	g_print("Clicked\r\n");
	//g_print(getContent_txtField(GTK_WIDGET(txtField)));
}

void GUI::chkbox_on(GtkWidget *widget){
	std::cout << "on" << std::endl;
	//activate_txtField(widget);
	/*
	 * TODO:
	 * User wants to edit form field manually. Set textfield
	 * editable and get value when "send" button is clicked
	 */
}

void GUI::chkbox_off(GtkWidget *widget){
	std::cout << "off" << std::endl;
	//deactivate_txtField(widget);
	/*
	 * TODO:
	 * Checkbox is off per default. That means that the form is
	 * filled automatically with dynamically generated data.
	 */
}

void GUI::chkbox_listen(GtkWidget *cbox){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cbox)))
		chkbox_on(cbox);
	else
		chkbox_off(cbox);
}

void GUI::create_helpWindow_about(){
	GtkWidget *helpWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(helpWindow), "About");
	gtk_widget_grab_focus(GTK_WIDGET(helpWindow));
	gtk_window_set_position(GTK_WINDOW(helpWindow),
				GTK_WIN_POS_CENTER);
	g_signal_connect(helpWindow, "destroy",
			 G_CALLBACK(gtk_widget_destroy), NULL);

	GtkWidget *helpGrid = gtk_vbox_new(FALSE, 0);
	const char *helpString = "\r\n Copyright: (C) 2016 Yakup Ates\r\n"
		" E-Mail: <Yakup.Ates@rub.de>\r\n"
		" Project: github.com/y-ates/AFaker\r\n"
		" License: GPLv3 (http://www.gnu.org/licenses/)  \r\n";

	GtkWidget *helpLabel = gtk_label_new(helpString);
	gtk_box_pack_start(GTK_BOX(helpGrid), helpLabel, FALSE, FALSE,
			   0);
	gtk_container_add(GTK_CONTAINER(helpWindow), helpGrid);

	gtk_widget_show_all(helpWindow);

	/*
	 * TODO:
	 * Get a logo done. Insert here.
	 */
}

GtkWidget* GUI::create_button(const char *label){
	GtkWidget *button = gtk_button_new_with_label(label);

	gtk_widget_show(button);

	return button;
}

GtkWidget* GUI::create_menubar(GtkWidget *grid_menubar, GtkWidget *main_window){
	/*
	 * TODO:
	 * File->Open->* needs a file browser etc.
	 */

	GtkWidget *menubar = gtk_menu_bar_new();
	GtkWidget *fileMenu = gtk_menu_new();
	GtkWidget *helpMenu = gtk_menu_new();
	GtkWidget *menu_file;
	GtkWidget *menu_choose = gtk_menu_new();
	GtkWidget *menu_file_choose;
	GtkWidget *menu_file_mailList;
	GtkWidget *menu_file_nameList;
	GtkWidget *menu_help;
	GtkWidget *menu_help_about;
	GtkWidget *menu_quit;

	/* Menu File */
	menu_file = gtk_menu_item_new_with_label("File");
	menu_file_choose = gtk_menu_item_new_with_label("Open");
	menu_file_mailList = gtk_menu_item_new_with_label("E-Mail addresses");
	menu_file_nameList = gtk_menu_item_new_with_label("Names");
	menu_quit = gtk_menu_item_new_with_label("Quit");
	/* Menu Help */
	menu_help = gtk_menu_item_new_with_label("Help");
	menu_help_about = gtk_menu_item_new_with_label("About");

	/* File -> */
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_file), fileMenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), menu_file_choose);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), menu_quit);

	/* File -> open */
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_file_choose),
				  menu_choose);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_choose),
			      menu_file_nameList);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_choose),
			      menu_file_mailList);

	/* Help -> */
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_help), helpMenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpMenu),
			      menu_help_about);

	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_file);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_help);
	gtk_box_pack_start(GTK_BOX(grid_menubar), menubar, FALSE,
			   FALSE, 0);

	g_signal_connect(G_OBJECT(menu_quit), "activate",
			 G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(menu_file_mailList), "activate",
			 G_CALLBACK(choose_mailList), main_window);
	g_signal_connect(G_OBJECT(menu_help_about), "activate",
			 G_CALLBACK(GUI::create_helpWindow_about),
			 NULL);

	return menubar;
}

void GUI::choose_mailList(GtkWidget *parent_window, gpointer data){
	GtkWidget *dialog;
	dialog = gtk_file_chooser_dialog_new("Open File",
					     GTK_WINDOW(parent_window),
					     GTK_FILE_CHOOSER_ACTION_OPEN,
					     GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
					     GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
					     NULL);
	if(gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT){
		char *filename;
		filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER (dialog));
		std::cout << filename << std::endl;
		// open_file (filename);
		// g_free (filename);
	}
	gtk_widget_destroy(dialog);
}

GtkWidget* GUI::create_txtField(){
	/*
	 * TODO:
	 * Get content of textfield if "edit"-checkbox is checked.
	 * We need to be able to address each textfield individually.
	 */
	GtkWidget *tField = gtk_entry_new();

	return tField;
}

const gchar* GUI::getContent_txtField(GtkWidget *txtField){
	return gtk_entry_get_text(GTK_ENTRY(txtField));
}

void GUI::deactivate_txtField(GtkWidget *txtField){
	gtk_editable_set_editable(GTK_EDITABLE(txtField), FALSE);
	gtk_widget_set_can_focus(GTK_WIDGET(txtField), FALSE);

	const GdkColor GREY = {0, 48000, 48000, 48000};
	gtk_widget_modify_base(txtField, GTK_STATE_NORMAL, &GREY);

	//gtk_entry_set_text(GTK_ENTRY(tField), "TEST");
}

void GUI::activate_txtField(GtkWidget *txtField){
	gtk_editable_set_editable(GTK_EDITABLE(txtField), TRUE);
	gtk_widget_set_can_focus(GTK_WIDGET(txtField), TRUE);

	const GdkColor WHITE = {0, 65535, 65535, 65535};
	gtk_widget_modify_base(txtField, GTK_STATE_NORMAL, &WHITE);
}


GtkWidget* GUI::create_checkbox(const char *label){
	/*
	 * TODO:
	 * We need to be able to address each textfield individually.
	 */

	GtkWidget *cbox;

	cbox = gtk_check_button_new_with_label(label);

	g_signal_connect(GTK_WIDGET(cbox), "toggled",
			 G_CALLBACK(GUI::chkbox_listen), cbox);


	return cbox;
}

GtkWidget* GUI::create_label(const char *txt_label){
	/*
	 * TODO:
	 * We need to be able to address each textfield individually.
	 */

	GtkWidget *label = gtk_label_new(txt_label);

	gtk_label_set_text(GTK_LABEL(label), txt_label);

	return label;
}

GtkWidget* GUI::pack_label_txtField_checkbox(GtkWidget *label,
					     GtkWidget *txtField,
					     GtkWidget *checkbox){
	/*
	 * TODO:
	 * Can we address the GtkWidgets contained in a grid
	 * individually?
	 */

	GtkWidget *grid_label = gtk_hbox_new(FALSE, 0);
	GtkWidget *grid_txtField = gtk_hbox_new(FALSE, 0);
	GtkWidget *grid_checkbox = gtk_hbox_new(FALSE, 0);
	GtkWidget *hgrid_all = gtk_hbox_new(FALSE, 0);

	/*
	 * Every widget get its own grid.
	 */
	gtk_box_pack_start(GTK_BOX(grid_label), label, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(grid_txtField), txtField, FALSE,
			   FALSE, 0);
	gtk_box_pack_start(GTK_BOX(grid_checkbox), checkbox, FALSE,
			   FALSE, 0);

	/*
	 * Put all grids together.
	 */
	gtk_box_pack_start(GTK_BOX(hgrid_all), grid_label, FALSE,
			   FALSE, 0);
	gtk_box_pack_start(GTK_BOX(hgrid_all), grid_txtField, FALSE,
			   FALSE, 5);
	gtk_box_pack_start(GTK_BOX(hgrid_all), grid_checkbox, FALSE,
			   FALSE, 0);


	return hgrid_all;
}

GUI::grid_Line GUI::create_grid_packed(std::vector<std::string> labels){
	/*
	 * We are going to create the widgets like this but dynamically.
	 * The form names will be extracted and used here (of the website).
	 */		
	struct grid_Line form;
		
	int label_count = labels.size();

	for(int i=0; i<label_count; i++){
		form.txtField= GUI::create_txtField();
		form.checkbox = GUI::create_checkbox("Edit");
		form.label = GUI::create_label(labels[i].c_str());

		form.gridLine = GUI::pack_label_txtField_checkbox(form.label,
								  form.txtField,
								  form.checkbox);
		gtk_box_pack_start(GTK_BOX(form.hbox), form.gridLine, FALSE,
				   FALSE, 0);
	}

	// We can get the form name like this
	//std::cout << gtk_label_get_text(GTK_LABEL(form.label)) << endl;

	return form;
}