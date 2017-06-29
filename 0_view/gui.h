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

#ifndef _GUI_H
#define _GUI_H

#include <gtk/gtk.h>
#include <iostream>
#include <cstring>
//#include <string>
#include <vector>
#include "form.h"

#define W_TITLE "AFaker - Create fake accounts easily"
#define W_HEIGHT 800
#define W_WIDTH 600
#define W_BORDER_WIDTH 2
#define MAX_FORMS 100


class GUI{
 private:
    
 public:
    GUI(){
    }

    struct widgetContainer {
        GtkWidget* first;
        GtkWidget* second;
    };
    
    static void but_send_listen(GtkWidget* widget, std::vector<Form>& forms);
    static void but_clicked(GtkWidget* widget, GtkWidget *txtField);
    static void chkbox_on(GtkWidget* widget);
    static void chkbox_off(GtkWidget* widget);
    //static void chkbox_listen(GtkWidget* cbox, GtkWidget* txtField);
    static void chkbox_listen(widgetContainer context);
    static void choose_mailList(GtkWidget* widget, GtkWidget* parent_window);
    static void choose_nameList(GtkWidget* widget, GtkWidget* parent_window);
    static void create_helpWindow_about();
    static GtkWidget* create_button(const char* label);
    static GtkWidget* create_menubar(GtkWidget* grid_menubar,
                     GtkWidget* main_window);
    static GtkWidget* create_checkbox(const char* label, GtkWidget* txtField);
    static GtkWidget* create_label(const char* txt_label);
    static GtkWidget* create_txtField();
    static const gchar* getContent_txtField(GtkWidget* txtField);
    static void deactivate_txtField(GtkWidget* txtField);
    static void activate_txtField(GtkWidget* txtField);
    static GtkWidget* h_pack_three(GtkWidget* label, GtkWidget* txtField,
                                   GtkWidget* checkbox);
    static GtkWidget* v_pack(std::vector<GtkWidget*> widgets, int size);
    static std::vector<Form> create_grid_packed(std::vector<std::string> labels);
    static void start(int argc, char** argv);
};

#endif
