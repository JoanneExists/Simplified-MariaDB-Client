#include "main_window.h"
#include <gtk/gtk.h>

int activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window;
	
	window = gtk_application_window_new(app);
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
	gtk_window_set_title(GTK_WINDOW(window), "MariaDB Manager");
	gtk_window_present (GTK_WINDOW (window));
}

int create_main_window()
{
	GtkApplication *app;
	int app_status;
	
	app = gtk_application_new("org.gtk.mariadb", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	app_status = g_application_run (G_APPLICATION (app), 0, 0);
	g_object_unref(app);
}
