#include <gtk/gtk.h>
#include <mariadb/mysql.h>
#include "login.h"
int login_clicked(GtkWidget *dialog, gint response_id, gpointer user_data, GtkWidget *username_entry, GtkWidget *password_entry)
{
	// char arrays to hold username and password
	const gchar *username = gtk_entry_get_text(GTK_ENTRY(username_entry));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(password_entry));
    // start the server connection
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Failed to initialize MariaDB connection: %s\n", mysql_error(conn));
        return 1;
    }

    if (mysql_real_connect(conn, "localhost", "username", "password", "legislation", 0, NULL, 0) == NULL) {
        printf("Failed to connect to MariaDB database: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }
    gtk_widget_destroy(GTK_WIDGET(dialog));

	return 0;
}
// Callback function for handling Enter key press
gboolean on_key_press(GtkWidget *dialog, GdkEventKey *event, gpointer data, gint response_id, gpointer user_data, GtkWidget *username_entry, GtkWidget *password_entry) 
{
    if (event->keyval == GDK_KEY_Return || event->keyval == GDK_KEY_KP_Enter) {
        // Call button_activate function
        login_clicked(dialog, response_id, user_data, username_entry, password_entry);
        return TRUE;
    }
    return FALSE;
}
int create_dialog(GtkWindow *parent_window, gchar *message)
{
	// the dialog window itself
	GtkWidget *dialog = gtk_dialog_new();
	gtk_window_set_title(GTK_WINDOW(dialog), "Login to MariaDB");
	// create the content area and the box widget
	GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(content_area), box);
	// add the content area to the box and initialize box and content_area
	gtk_container_add(GTK_CONTAINER(content_area), box);
	// create the usernam and password entry widgets
	GtkWidget *username_entry = gtk_entry_new();
	GtkWidget *password_entry = gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(password_entry), FALSE);
	// add the labels and entry areas to the box
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Username:"), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), username_entry, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Password:"), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), password_entry, FALSE, FALSE, 0);
	// create the login button and connect the signals
	GtkWidget *login_button = gtk_dialog_add_button(GTK_DIALOG(dialog), "Login", GTK_RESPONSE_OK);
	GtkWidget *cancel_button = gtk_dialog_add_button(GTK_DIALOG(dialog), "Cancel", GTK_RESPONSE_CANCEL);
	g_signal_connect_swapped(login_button, "clicked", G_CALLBACK(login_clicked), dialog);
	g_signal_connect_swapped(cancel_button, "clicked", G_CALLBACK(gtk_widget_destroy), dialog);
	g_signal_connect(parent_window, "key-press-event", G_CALLBACK(on_key_press), login_button);
	// make the widgets that were added visible
	gtk_widget_show_all(dialog);
	return 0;
}

int create_login_window(GtkWindow *window, GtkApplication *app)
{
	create_dialog(window, "Log into MariaDB");
	return 0;
}
