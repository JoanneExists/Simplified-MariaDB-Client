#include <gtk/gtk.h>
#include "drop_down_menus.h"

int quit_app(GtkApplication *app, gpointer user_data)
{
	g_application_quit(G_APPLICATION(user_data));
	return 0;
}

int login(GtkApplication *app, gpointer user_data)
{
	
	return 0;
}

int create_menu_bar(GtkWidget *window, GtkApplication *app)
{
	GtkWidget *menu;
	GtkWidget *menu_bar;
	GtkWidget *file_menu;
	GtkWidget *file_mi;
	GtkWidget *login_mi;
	GtkWidget *edit_menu;
	GtkWidget *edit_mi;
	GtkWidget *edit_entry_mi;
	GtkWidget *edit_table_mi;
	GtkWidget *add_menu;
	GtkWidget *add_mi;
	GtkWidget *add_entry_mi;
	GtkWidget *add_table_mi;
	GtkWidget *delete_menu;
	GtkWidget *delete_mi;
	GtkWidget *delete_entry_mi;
	GtkWidget *delete_table_mi;
	GtkWidget *delete_db_mi;
	GtkWidget *quit_mi;
	GtkWidget *box;
	
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	gtk_container_add(GTK_CONTAINER(window), box);
	
	file_menu = gtk_menu_new();
	edit_menu = gtk_menu_new();
	add_menu = gtk_menu_new();
	delete_menu = gtk_menu_new();
	file_mi = gtk_menu_item_new_with_label("File");
	edit_mi = gtk_menu_item_new_with_label("Edit");
	edit_entry_mi = gtk_menu_item_new_with_label("Edit Entry");
	edit_table_mi = gtk_menu_item_new_with_label("Edit Table");
	add_mi = gtk_menu_item_new_with_label("Add");
	add_entry_mi = gtk_menu_item_new_with_label("Add Entry");
	add_table_mi = gtk_menu_item_new_with_label("Add Table");
	delete_mi = gtk_menu_item_new_with_label("Delete");
	delete_entry_mi = gtk_menu_item_new_with_label("Delete Entry");
	delete_table_mi = gtk_menu_item_new_with_label("Delete Table");
	delete_db_mi = gtk_menu_item_new_with_label("Delete Database");
	login_mi = gtk_menu_item_new_with_label("Login");
	quit_mi = gtk_menu_item_new_with_label("Quit");
	menu_bar = gtk_menu_bar_new();
	
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_mi), file_menu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit_mi), edit_menu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(add_mi), add_menu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(delete_mi), delete_menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), login_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), quit_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), edit_entry_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), edit_table_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), add_entry_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), add_table_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(delete_menu), delete_entry_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(delete_menu), delete_table_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(delete_menu), delete_db_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), edit_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), add_mi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), delete_mi);
    gtk_box_pack_start(GTK_BOX(box), menu_bar, FALSE, FALSE, 0);

	g_signal_connect(G_OBJECT(quit_mi), "activate", G_CALLBACK(quit_app), app);
	g_signal_connect(G_OBJECT(login_mi), "activate", G_CALLBACK(login), app);
	gtk_widget_show_all(window);
	
	return 0;
}
