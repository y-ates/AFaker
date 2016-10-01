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
	form = gui.create_grid_packed({"Name", "E-Mail", "Phone", "test", "a", "b", "c", "d", "e", "f", "g"});

	std::vector<Form> form1;
	form1 = gui.create_grid_packed({"test1", "test1", "test1", "test1",
				"test1", "test1", "test1", "test1", "test1",
				"test1", "test1", "test1"});


	for(unsigned int i=0; i<form.size(); ++i){
		gtk_box_pack_start(GTK_BOX(hbox0), form[i].get_hbox(), FALSE, FALSE, 0);
	}

	for(unsigned int i=0; i<form1.size(); ++i){
		gtk_box_pack_start(GTK_BOX(hbox1), form1[i].get_hbox(), FALSE, FALSE, 0);
	}

	//hbox0 = form[1].get_hbox();

	gui.create_menubar(grid_menubar, main_window);

	//GUI::deactivate_txtField(txt_name);


	GtkWidget *but_grid_send = gtk_vbox_new(FALSE, 0);
	GtkWidget *but_send = gui.create_button("Send");
	g_signal_connect(but_send, "clicked", G_CALLBACK(gui.but_send), NULL);

	GtkWidget *url_field = gui.create_txtField();
	gtk_entry_set_text(GTK_ENTRY(url_field), "SET URL");
	gtk_entry_set_max_length(GTK_ENTRY(url_field), 1000);
	gtk_entry_set_width_chars(GTK_ENTRY(url_field), 50);
	gtk_entry_set_alignment(GTK_ENTRY(url_field), 0.5f);
	GtkWidget *url_label = gui.create_label("URL: ");
	GtkWidget *url_label_field_grid = gtk_hbox_new(FALSE, 0);
	GtkWidget *url_field_grid = gtk_vbox_new(FALSE, 0);

	GtkWidget *seperator_h = gtk_hseparator_new();
	GtkWidget *seperator_v = gtk_vseparator_new();
	//GtkWidget *scrollbar = gtk_vscrollbar_new(0);
	//GtkWidget *scrollbar = gtk_scrolled_window_new(NULL, NULL);

	GtkWidget* alignment = gtk_alignment_new(0.5, 0.5, 0, 0);
	
	// MENUBAR
	gtk_box_pack_start(GTK_BOX(grid), grid_menubar, FALSE, FALSE, 0);

	// URL_LABEL - URL_FIELD - SEND_BUTTON
	gtk_box_pack_start(GTK_BOX(url_label_field_grid), url_label, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(url_field_grid), url_field, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(but_grid_send), but_send, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(hbox2), url_label_field_grid, FALSE, FALSE, 5);
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

	return 0;
}
