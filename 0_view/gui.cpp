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

#include "gui.h"
#include "form.h"


//void GUI::but_send_listen(){
//void GUI::but_send_listen(std::vector<Form> left, std::vector<Form> right){
void GUI::but_send_listen(GtkWidget* widget, std::vector<Form>& forms){
	g_print("Sending...\r\n");

	for(int i=0; i<forms.size(); ++i){
		deactivate_txtField(forms[i].get_txtField());
		std::cout << i << ": " << gtk_entry_get_text(GTK_ENTRY(forms[i].get_txtField()))
			  << std::endl;
	}
	
	/*
	 * TODO:
	 * Get value of all forms and call send function.
	 */
}

void GUI::but_clicked(GtkWidget* widget, GtkWidget* txtField){
	g_print("Clicked\r\n");
	//g_print(getContent_txtField(GTK_WIDGET(txtField)));
}

void GUI::create_helpWindow_about(){
	GtkWidget* helpWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(helpWindow), "About");
	gtk_widget_grab_focus(GTK_WIDGET(helpWindow));
	gtk_window_set_position(GTK_WINDOW(helpWindow),
				GTK_WIN_POS_CENTER);
	g_signal_connect(helpWindow, "destroy",
			 G_CALLBACK(gtk_widget_destroy), NULL);

	GtkWidget* helpGrid = gtk_vbox_new(FALSE, 0);
	const char* helpString = "\r\n Copyright: (C) 2016 Yakup Ates\r\n"
		" E-Mail: <Yakup.Ates@rub.de>\r\n"
		" Project: github.com/y-ates/AFaker\r\n"
		" License: GPLv3 (http://www.gnu.org/licenses/)  \r\n";

	GtkWidget* helpLabel = gtk_label_new(helpString);
	gtk_box_pack_start(GTK_BOX(helpGrid), helpLabel, FALSE, FALSE,
			   0);
	gtk_container_add(GTK_CONTAINER(helpWindow), helpGrid);

	gtk_widget_show_all(helpWindow);

	/*
	 * TODO:
	 * Get a logo done. Insert here.
	 */
}

GtkWidget* GUI::create_button(const char* label){
	GtkWidget* button = gtk_button_new_with_label(label);

	gtk_widget_show(button);

	return button;
}

GtkWidget* GUI::create_menubar(GtkWidget* grid_menubar, GtkWidget* main_window){
	/*
	 * TODO:
	 * File->Open->* needs a file browser etc.
	 */

	GtkWidget* menubar = gtk_menu_bar_new();
	GtkWidget* fileMenu = gtk_menu_new();
	GtkWidget* helpMenu = gtk_menu_new();
	GtkWidget* menu_file;
	GtkWidget* menu_choose = gtk_menu_new();
	GtkWidget* menu_file_choose;
	GtkWidget* menu_file_mailList;
	GtkWidget* menu_file_nameList;
	GtkWidget* menu_help;
	GtkWidget* menu_help_about;
	GtkWidget* menu_quit;

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

void GUI::choose_mailList(GtkWidget* parent_window, gpointer data){
	GtkWidget* dialog;
	dialog = gtk_file_chooser_dialog_new("Open File",
					     GTK_WINDOW(parent_window),
					     GTK_FILE_CHOOSER_ACTION_OPEN,
					     GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
					     GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
					     NULL);
	if(gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT){
		char* filename;
		filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER (dialog));
		std::cout << filename << std::endl;
		// open_file (filename);
		// g_free (filename);
	}
	gtk_widget_destroy(dialog);
}

void GUI::choose_nameList(GtkWidget* parent_window, gpointer data){
	/*
	 * TODO
	 */
}

const gchar* GUI::getContent_txtField(GtkWidget* txtField){
	return gtk_entry_get_text(GTK_ENTRY(txtField));
}

GtkWidget* GUI::h_pack_three(GtkWidget* label, GtkWidget* txtField,
			    GtkWidget* checkbox){
	GtkWidget* hgrid = gtk_hbox_new(FALSE, 0);

	// Put all GtkWidgets in one hbox
	gtk_box_pack_start(GTK_BOX(hgrid), label, FALSE,
			   FALSE, 0);
	gtk_box_pack_start(GTK_BOX(hgrid), txtField, FALSE,
			   FALSE, 5);
	gtk_box_pack_start(GTK_BOX(hgrid), checkbox, FALSE,
			   FALSE, 0);


	return hgrid;
}

GtkWidget* GUI::v_pack(std::vector<GtkWidget*> widgets, int size){
	GtkWidget* vgrid = gtk_vbox_new(FALSE, 0);
	
	if(!widgets.empty()){
		if(size < MAX_FORMS){
			for(int i=0; i<size; ++i){
				gtk_box_pack_start(GTK_BOX(vgrid), widgets[i],
						   FALSE, FALSE, 0);
			}

			return vgrid;
		}
	}
	
	return (GtkWidget*) NULL;
}

GtkWidget* GUI::create_txtField(){
	/*
	 * TODO:
	 * Get content of textfield if "edit"-checkbox is checked.
	 * We need to be able to address each textfield individually.
	 */
	GtkWidget* tField = gtk_entry_new();

	return tField;
}

GtkWidget* GUI::create_checkbox(const char* label, GtkWidget* txtField){
	/*
	 * TODO:
	 * We need to be able to address each textfield individually.
	 */

	GtkWidget* cbox;

	cbox = gtk_check_button_new_with_label(label);

	g_signal_connect(GTK_WIDGET(cbox), "toggled",
			 G_CALLBACK(GUI::chkbox_listen), (cbox, txtField));
	deactivate_txtField(txtField);

	return cbox;
}

GtkWidget* GUI::create_label(const char* txt_label){
	/*
	 * TODO:
	 * We need to be able to address each textfield individually.
	 */

	GtkWidget* label = gtk_label_new(txt_label);

	gtk_label_set_text(GTK_LABEL(label), txt_label);

	return label;
}

std::vector<Form> GUI::create_grid_packed(std::vector<std::string> labels){
	/*
	 * We are going to create the widgets like this but dynamically.
	 * The form names will be extracted and used here (of the website).
	 */		
	int label_count = labels.size();
	std::vector<Form> forms(label_count);

	for(int i=0; i<label_count; ++i){
		forms[i].set_txtField(forms[i].create_txtField());
		// Signal handler works this way... :/
		forms[i].set_checkbox(GUI::create_checkbox("Edit", forms[i].get_txtField()));
		//(forms[i].create_checkbox("Edit"));
		forms[i].set_label(forms[i].create_label(labels[i].c_str()));

		forms[i].set_vbox(h_pack_three(forms[i].get_label(),
					       forms[i].get_txtField(),
					       forms[i].get_checkbox()));
		gtk_box_pack_start(GTK_BOX(forms[i].get_hbox()), forms[i].get_vbox(),
				   FALSE, FALSE, 0);
	}

	// We can get the form name like this
	//std::cout << gtk_label_get_text(GTK_LABEL(form.label)) << endl;

	return forms;
}

/*
 * GUI entry point.
 */
void GUI::start(int argc, char** argv){
	GtkWidget* main_window;
	
	gtk_init(&argc, &argv);

	main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(main_window),
			     W_TITLE);
	//gtk_window_set_default_size(GTK_WINDOW(main_window), W_HEIGHT, W_WIDTH);
	gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
	gtk_window_set_resizable(GTK_WINDOW(main_window), FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(main_window),
				       W_BORDER_WIDTH);
	g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit),
			 NULL);

	//cout << gtk_window_get_can_focus(GTK_WINDOW(main_window));
	//gtk_widget_grab_focus(main_window);

	/* Grid */
	GtkWidget* grid = gtk_vbox_new(FALSE, 0);
	GtkWidget* grid_menubar = gtk_vbox_new(FALSE, 0);
	GtkWidget* hbox2 = gtk_hbox_new(FALSE, 0);
	//GtkWidget* hbox1 = gtk_hbox_new(FALSE, 0);
	GtkWidget* hbox0 = gtk_vbox_new(FALSE, 0);
	
	GtkWidget* hbox1 = gtk_vbox_new(FALSE, 0);
	GtkWidget* hbox3 = gtk_hbox_new(FALSE, 0);
	
	std::vector<Form> form;
	form = create_grid_packed({"Name", "E-Mail", "Phone", "test", "a",
				"b", "c", "d", "e", "f", "g"});

	std::vector<Form> form1;
	form1 = create_grid_packed({"test1", "test1", "test1", "test1",
				"test1", "test1", "test1", "test1", "test1",
				"test1", "test1", "test1"});


	for(unsigned int i=0; i<form.size(); ++i){
		gtk_box_pack_start(GTK_BOX(hbox0), form[i].get_hbox(), FALSE,
				   FALSE, 0);
	}

	for(unsigned int i=0; i<form1.size(); ++i){
		gtk_box_pack_start(GTK_BOX(hbox1), form1[i].get_hbox(), FALSE,
				   FALSE, 0);
	}

	std::vector<Form> all_form;
	all_form.reserve( form.size() + form1.size() ); // preallocate memory
	all_form.insert( all_form.end(), form.begin(), form.end() );
	all_form.insert( all_form.end(), form1.begin(), form1.end() );

	create_menubar(grid_menubar, main_window);

	//std::cout << gtk_entry_get_text(GTK_ENTRY(form[0].get_txtField())) << std::endl;
	gtk_entry_set_text(GTK_ENTRY(form[0].get_txtField()), "bb");
	
	GtkWidget* but_grid_send = gtk_vbox_new(FALSE, 0);
	GtkWidget* but_send = create_button("Send");
	g_signal_connect(but_send, "clicked", G_CALLBACK(but_send_listen), &all_form);

	GtkWidget* url_field = create_txtField();
	gtk_entry_set_text(GTK_ENTRY(url_field), "SET URL");
	gtk_entry_set_max_length(GTK_ENTRY(url_field), 1000);
	gtk_entry_set_width_chars(GTK_ENTRY(url_field), 50);
	gtk_entry_set_alignment(GTK_ENTRY(url_field), 0.5f);
	GtkWidget* url_label = create_label("URL: ");
	GtkWidget* url_label_field_grid = gtk_hbox_new(FALSE, 0);
	GtkWidget* url_field_grid = gtk_vbox_new(FALSE, 0);

	GtkWidget* seperator_h = gtk_hseparator_new();
	GtkWidget* seperator_v = gtk_vseparator_new();
	//GtkWidget *scrollbar = gtk_vscrollbar_new(0);
	//GtkWidget *scrollbar = gtk_scrolled_window_new(NULL, NULL);

	GtkWidget* alignment = gtk_alignment_new(0.5, 0.5, 0, 0);
	
	// MENUBAR
	gtk_box_pack_start(GTK_BOX(grid), grid_menubar, FALSE, FALSE, 0);

	// URL_LABEL - URL_FIELD - SEND_BUTTON
	gtk_box_pack_start(GTK_BOX(url_label_field_grid), url_label, FALSE,
			   FALSE, 5);
	gtk_box_pack_start(GTK_BOX(url_field_grid), url_field, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(but_grid_send), but_send, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(hbox2), url_label_field_grid, FALSE, FALSE,
			   5);
	gtk_box_pack_start(GTK_BOX(hbox2), url_field_grid, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(hbox2), but_grid_send, FALSE, FALSE, 5);
	gtk_container_add(GTK_CONTAINER(alignment), hbox2);
	gtk_box_pack_start(GTK_BOX(grid), alignment, FALSE, FALSE, 5);

	// Seperator
	gtk_box_pack_start(GTK_BOX(grid), seperator_h, FALSE, FALSE, 5);

	// ALL FORMS
	//gtk_container_add(GTK_CONTAINER(alignment), hbox0);
	//gtk_box_pack_start(GTK_BOX(grid), alignment, FALSE, FALSE, 0);


	//GtkWidget* alignment_right = gtk_alignment_new(0.5, 0.5, 0, 0);
	//gtk_container_add(GTK_CONTAINER(alignment_right), hbox0);
	gtk_box_pack_start(GTK_BOX(hbox3), hbox0, FALSE, FALSE, 10);
	gtk_box_pack_start(GTK_BOX(hbox3), seperator_v, FALSE, FALSE, 25);
	gtk_box_pack_end(GTK_BOX(hbox3), hbox1, FALSE, FALSE, 10);
	gtk_box_pack_start(GTK_BOX(grid), hbox3, FALSE, FALSE, 10);

	// MERGE ALL
	gtk_container_add(GTK_CONTAINER(main_window), grid);
	gtk_widget_show_all(main_window);

	gtk_main();
}

/***************************************************
 *
 * These functions below should take place in "Form"...
 * 
 ***************************************************/

void GUI::chkbox_on(GtkWidget* widget){
	//std::cout << "on" << std::endl;
	activate_txtField(widget);
	/*
	 * TODO:
	 * User wants to edit form field manually. Set textfield
	 * editable and get value when "send" button is clicked
	 */
}

void GUI::chkbox_off(GtkWidget* widget){
	//std::cout << "off" << std::endl;
	deactivate_txtField(widget);
	/*
	 * TODO:
	 * Checkbox is off per default. That means that the form is
	 * filled automatically with dynamically generated data.
	 */
}

void GUI::chkbox_listen(GtkWidget* cbox, GtkWidget* txtField){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cbox)))
		chkbox_on(txtField);
	else
		chkbox_off(txtField);
}

void GUI::deactivate_txtField(GtkWidget* txtField){
	gtk_editable_set_editable(GTK_EDITABLE(txtField), FALSE);
	gtk_widget_set_can_focus(GTK_WIDGET(txtField), FALSE);

	const GdkColor GREY = {0, 48000, 48000, 48000};
	gtk_widget_modify_base(txtField, GTK_STATE_NORMAL, &GREY);

	//gtk_entry_set_text(GTK_ENTRY(tField), "TEST");
}

void GUI::activate_txtField(GtkWidget* txtField){
	gtk_editable_set_editable(GTK_EDITABLE(txtField), TRUE);
	gtk_widget_set_can_focus(GTK_WIDGET(txtField), TRUE);

	const GdkColor WHITE = {0, 65535, 65535, 65535};
	gtk_widget_modify_base(txtField, GTK_STATE_NORMAL, &WHITE);
}
