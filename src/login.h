#include <gtk/gtk.h>

#ifndef LOGIN_H_ 
#define LOGIN_H_

int create_dialog(gchar *message);
int create_login_window(GtkWindow *window, GtkApplication *app);

#endif
