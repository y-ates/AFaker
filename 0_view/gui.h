#ifndef _GUI_H
#define _GUI_H

#include <gtk/gtk.h>
#include <iostream>
#include <string>
#include <vector>

//using namespace std;

class GUI{
 private:
	
 public:
	GUI(){
	}

	struct grid_Line {
		GtkWidget *hbox = gtk_vbox_new(FALSE, 5);
		GtkWidget *gridLine = gtk_vbox_new(FALSE, 0);;
		GtkWidget *label;
		GtkWidget *txtField;
		GtkWidget *checkbox;
	};
	
	static void but_send(GtkWidget *widget, gpointer data);
	static void but_clicked(GtkWidget *widget, GtkWidget *txtField);
	static void chkbox_on(GtkWidget *widget);
	static void chkbox_off(GtkWidget *widget);
	static void chkbox_listen(GtkWidget *cbox);
	static void create_helpWindow_about();
	static GtkWidget *create_button(const char *label);
	static GtkWidget *create_menubar(GtkWidget *grid_menubar,
					 GtkWidget *main_window);
	static void choose_mailList(GtkWidget *parent_window, gpointer data);
	static GtkWidget *create_txtField();
	static const gchar *getContent_txtField(GtkWidget *txtField);
	static void deactivate_txtField(GtkWidget *txtField);
	static void activate_txtField(GtkWidget *txtField);
	static GtkWidget *create_checkbox(const char *label);
	static GtkWidget *create_label(const char *txt_label);
	static GtkWidget *pack_label_txtField_checkbox(GtkWidget *label,
						       GtkWidget *txtField,
						       GtkWidget *checkbox);
	static grid_Line create_grid_packed(std::vector<std::string> labels);
};

#endif
