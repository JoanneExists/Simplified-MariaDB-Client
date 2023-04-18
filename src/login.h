#include <gtk/gtk.h>

#ifndef LOGIN_H_ 
#define LOGIN_H_

int create_dialog(GtkWindow *parent_window, gchar *message);
int create_login_window(GtkWindow *window, GtkApplication *app);
int login_clicked(GtkWidget *dialog, gint response_id, gpointer user_data, GtkWidget *username_entry, GtkWidget *password_entry);

#endif
