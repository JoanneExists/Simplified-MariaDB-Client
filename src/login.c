#include <gtk/gtk.h>

int maria_db_login()
{
	return 0;
}
int create_dialog(GtkWindow *parent_window, gchar *message)
{
	GtkWidget *dialog;
	GtkWidget *dialog_contents;
	GtkWidget *login_input_field;
	GtkWidget *pwd_input_field;
	GtkWidget *login_label;
	GtkWidget *pwd_label;
	GtkDialogFlags flags;

	dialog =  gtk_dialog_new_with_buttons ("Log into MariaDB",
                                      parent_window,
                                      flags,
                                      "Login",
                                      GTK_RESPONSE_ACCEPT,
                                      "Cancel",
                                      GTK_RESPONSE_REJECT,
                                      NULL);
    dialog_contents = gtk_dialog_get_content_area (GTK_DIALOG (dialog));             
    login_label = gtk_label_new (message);
	
	g_signal_connect_swapped (dialog,
                           "response",
                           G_CALLBACK (gtk_widget_destroy),
                           dialog);
	gtk_box_pack_start(GTK_BOX (dialog_contents), login_label, FALSE, FALSE, 0);
	gtk_widget_show (dialog);
	return 0;
}

int create_login_window(GtkWindow *window, GtkApplication *app)
{
	create_dialog(window, "Log into MariaDB");
	return 0;
}
