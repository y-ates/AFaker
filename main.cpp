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

#include "0_view/gui.h"

int main(int argc, char *argv[]){
	/* Init main window */
	GUI gui;
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

	//cout << gtk_window_get_can_focus(GTK_WINDOW(main_window));
	//gtk_widget_grab_focus(main_window);

	/* Grid */
	GtkWidget *grid = gtk_vbox_new(FALSE, 0);
	GtkWidget *grid_menubar = gtk_vbox_new(FALSE, 0);
	GtkWidget *hbox1 = gtk_hbox_new(FALSE, 0);
	GtkWidget *hbox0 = gtk_hbox_new(FALSE, 0);
	/*
	 * TODO:
	 * Working with structs and thus being able to individually address the
	 * single grids and its elements will solve many problems. 
	 */
	struct GUI::grid_Line form;
	form = gui.create_grid_packed({"Name", "E-Mail", "Phone", "test"});
	hbox0 = form.hbox;

	gui.create_menubar(grid_menubar, main_window);

	/*
	 * I think we won't need individual buttons for every textfield later
	 * on. A checkbox next to the textfield will suffice to control whether
	 * the user wants to set the value automatically or manually.
	 * A button "send" to actually submit the forms is needed.
	 */
	//GUI::deactivate_txtField(txt_name);


	GtkWidget *but_grid_send = gtk_vbox_new(FALSE, 0);
	GtkWidget *but_send = gui.create_button("Send");
	g_signal_connect(but_send, "clicked", G_CALLBACK(gui.but_send), NULL);

	/* Table packing */
	// GtkWidget *table = gtk_table_new(10, 10, TRUE);
	// gtk_container_add(GTK_CONTAINER(main_window), table);
	// gtk_table_attach_defaults(GTK_TABLE(table), grid_menubar, 0, 10, 0, 1);
	// gtk_table_attach_defaults(GTK_TABLE(table), hbox0, 0, 3, 1, 3);
	// gtk_table_attach_defaults(GTK_TABLE(table), but_send, 9, 10, 9, 10);

	/*
	 * TODO:
	 * Packing can be done much easier. Use table for textfields, buttons.
	 * Do we want a fixed window size?
	 * How do we handle many forms? What about a maximum count of allowed
	 * forms?
	 */
	gtk_box_pack_start(GTK_BOX(grid), grid_menubar, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(grid), hbox0, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(but_grid_send), but_send, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(hbox1), but_grid_send, FALSE, FALSE, 50);
	gtk_box_pack_start(GTK_BOX(grid), hbox1, FALSE, FALSE, 5);

	gtk_container_add(GTK_CONTAINER(main_window), grid);
	gtk_widget_show_all(main_window);

	gtk_main();

	return 0;
}

