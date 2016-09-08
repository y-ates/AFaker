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

#include <gtk/gtk.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GUI{
private:
	
public:
	GUI(){
	}

	static void test(GtkWidget *widget, gpointer data){
		g_print("Oh my God look at her ....\r\n");
		g_print("---------------------------\r\n");
	}

	static void but_clicked(GtkWidget *widget, GtkWidget *txtField){
		g_print("Clicked\r\n");
		//g_print(getContent_txtField(GTK_WIDGET(txtField)));
	}


	static void create_helpWindow_about(){
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

	static GtkWidget *create_button(const char *label, GtkWidget *txtField){
		GtkWidget *button = gtk_button_new_with_label(label);

		g_signal_connect(button, "clicked",
				 G_CALLBACK(GUI::but_clicked), (button, txtField));
		gtk_widget_show(button);

		return button;
	}

	static GtkWidget *create_menubar(GtkWidget *grid_menubar){
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
		g_signal_connect(G_OBJECT(menu_help_about), "activate",
				 G_CALLBACK(GUI::create_helpWindow_about),
				 NULL);

		return menubar;
	}

	static GtkWidget *create_txtField(){
		/*
		 * TODO:
		 * Get content of textfield if "edit"-checkbox is checked.
		 * We need to be able to address each textfield individually.
		 */
		GtkWidget *tField = gtk_entry_new();
		
		return tField;
	}

	static const gchar *getContent_txtField(GtkWidget *txtField){
		return gtk_entry_get_text(GTK_ENTRY(txtField));
	}

	static void deactivate_txtField(GtkWidget *txtField){
		gtk_editable_set_editable(GTK_EDITABLE(txtField), FALSE);
		gtk_widget_set_can_focus(GTK_WIDGET(txtField), FALSE);
		
		const GdkColor GREY = {0, 48000, 48000, 48000};
		gtk_widget_modify_base(txtField, GTK_STATE_NORMAL, &GREY);

		//gtk_entry_set_text(GTK_ENTRY(tField), "TEST");
	}


	static GtkWidget *create_checkbox(const char *label){
		/*
		 * TODO:
		 * We need to be able to address each textfield individually.
		 */

		GtkWidget *cbox;

		cbox = gtk_check_button_new_with_label(label);

		return cbox;
	}

	static GtkWidget *create_label(const char *txt_label){
		/*
		 * TODO:
		 * We need to be able to address each textfield individually.
		 */

		GtkWidget *label = gtk_label_new(txt_label);

		gtk_label_set_text(GTK_LABEL(label), txt_label);
		
		return label;
	}

	static GtkWidget *pack_label_txtField_checkbox(GtkWidget *label,
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
	
};

int main(int argc, char *argv[]){
	/* Init main window */
	GtkWidget *main_window;		
	gtk_init(&argc, &argv);

	main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	gtk_window_set_title(GTK_WINDOW(main_window),
			     "AFaker - Create fake accounts easily");
	gtk_window_set_default_size(GTK_WINDOW(main_window), 800, 600);
	gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(main_window), 2);
	g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit),
			 NULL);
        
	/* Grid */
	GtkWidget *grid = gtk_vbox_new(FALSE, 0);
	GtkWidget *grid1 = gtk_hbox_new(FALSE, 0);
	GtkWidget *grid2 = gtk_hbox_new(FALSE, 0);
	GtkWidget *grid3 = gtk_hbox_new(FALSE, 0);
	GtkWidget *grid4 = gtk_hbox_new(FALSE, 0);
	GtkWidget *grid_menubar = gtk_vbox_new(FALSE, 0);
	GtkWidget *vbox1 = gtk_vbox_new(FALSE, 0);	
	GtkWidget *vbox2 = gtk_vbox_new(FALSE, 0);
	GtkWidget *hbox1 = gtk_hbox_new(FALSE, 0);

	GUI::create_menubar(grid_menubar);
	/* Buttons */
	/*
	 * I think we won't need individual buttons for every textfield later
	 * on. A checkbox next to the textfield will suffice to control whether
	 * the user wants to set the value automatically or manually.
	 * A button "send" to actually submit the forms is needed.
	 */
	GtkWidget *txt_name = GUI::create_txtField();
	GUI::deactivate_txtField(txt_name);
	GtkWidget *txt_email = GUI::create_txtField();
	GtkWidget *but_setName;
	GtkWidget *but_setEmail;
	but_setName = GUI::create_button("Set name", txt_name);
	but_setEmail = GUI::create_button("set e-mail", txt_email);
	//but_setEmail = gtk_button_new_with_label("Set e-mail");
	//txt_name = gtk_entry_new();
	//txt_email = gtk_entry_new();
	
	//g_signal_connect(but_setName, "clicked", G_CALLBACK(GUI::test), NULL);
	//g_signal_connect(but_setEmail, "clicked", G_CALLBACK(GUI::test), NULL);


	/*
	 * We are going to create the widgets like this but dynamically.
	 * The form names will be extracted and used here (of the website).
	 */
	GtkWidget *hbox0 = gtk_vbox_new(FALSE, 5);
	GtkWidget *tstGrid;
	GtkWidget *tstLabel;
	GtkWidget *tstTxtField;
	GtkWidget *tstCheckbox;
	
	vector<string> labels {"Name", "E-Mail", "Phone"};
	const char *asd[] = {"Name", "E-Mail", "Phone"};
	for(int i=0; i<3; i++){
		tstGrid = gtk_vbox_new(FALSE, 0);
		tstLabel = GUI::create_label(labels[i].c_str());
		tstTxtField = GUI::create_txtField();
		tstCheckbox = GUI::create_checkbox("Edit");
		tstGrid = GUI::pack_label_txtField_checkbox(tstLabel, tstTxtField,
							    tstCheckbox);
		gtk_box_pack_start(GTK_BOX(hbox0), tstGrid, FALSE, FALSE, 0);

	}
	
	/*
	 * TODO:
	 * Packing can be done much easier. Use table for textfields, buttons.
	 */
	gtk_box_pack_start(GTK_BOX(grid), grid_menubar, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(grid), hbox1, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(hbox1), hbox0, FALSE, FALSE, 5);

	//gtk_box_pack_start(GTK_BOX(hbox1), vbox2, FALSE, FALSE, 5);
	//gtk_box_pack_start(GTK_BOX(hbox1), vbox1, FALSE, FALSE, 5);

	// gtk_box_pack_start(GTK_BOX(vbox1), grid1, FALSE, FALSE, 2);
	// gtk_box_pack_start(GTK_BOX(vbox1), grid2, FALSE, FALSE, 2);
	// gtk_box_pack_start(GTK_BOX(vbox2), grid3, FALSE, FALSE, 2);
	// gtk_box_pack_start(GTK_BOX(vbox2), grid4, FALSE, FALSE, 2);
	
	// gtk_box_pack_start(GTK_BOX(grid1), but_setName, FALSE, FALSE, 0);
	// gtk_box_pack_start(GTK_BOX(grid2), but_setEmail, FALSE, FALSE, 0);
	// gtk_box_pack_start(GTK_BOX(grid3), txt_name, FALSE, FALSE, 0);
	// gtk_box_pack_start(GTK_BOX(grid4), txt_email, FALSE, FALSE, 0);
	
	gtk_container_add(GTK_CONTAINER(main_window), grid);
	gtk_widget_show_all(main_window);			 
	
	gtk_main();	
	
	return 0;
}

