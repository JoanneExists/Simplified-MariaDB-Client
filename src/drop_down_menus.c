#include <gtk/gtk.h>
#include "drop_down_menus.h"

int create_menu_bar(GtkWidget *window)
{
	GtkWidget *menu;
	GtkWidget *menu_bar;
	GtkWidget *file_menu;
	GtkWidget *edit_menu;
	GtkWidget *add_menu;
	GtkWidget *delete_menu;
	GtkWidget *quit_menu;
	
	menu = gtk_menu_new();
	file_menu = gtk_menu_item_new_with_label("File");
	menu_bar = gtk_menu_bar_new();
	gtk_container_add(GTK_CONTAINER(window), menu_bar);
	
	gtk_menu_bar_append(GTK_MENU_BAR(menu_bar), file_menu);
    
    gtk_widget_show(menu_bar);
	gtk_widget_show(file_menu);
}
