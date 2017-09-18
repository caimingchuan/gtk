#include <stdlib.h>
#include <gtk/gtk.h>
gint count = 0;
char buf[5];
void increase(GtkWidget *widget, gpointer label)
{
    count++;
    sprintf(buf, "%d", count);
    gtk_label_set_text(label, buf);
}
void decrease(GtkWidget *widget, gpointer label)
{
    count--;
    sprintf(buf, "%d", count);
    gtk_label_set_text(label, buf);
}
void exit_app(void)
{
    printf("exit ......................\n");
    gtk_main_quit();
}

GdkPixbuf *create_pixbuf(const gchar *filename)
{
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);
    if (pixbuf == NULL)
    {
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }

    return pixbuf;
}

int main (int argc, char*argv[])
{
    GtkWidget *win = NULL;
    GtkWidget *frame = NULL;
    GtkWidget *label = NULL;
    GtkWidget *plus = NULL;
    GtkWidget *minus = NULL;
    /* Initialize GTK+ */
    gtk_init (&argc, &argv);

    /* Create the main window */
    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title (GTK_WINDOW (win), "icon");

    gtk_window_set_default_size(GTK_WINDOW(win), 600, 600);

    gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);

    gtk_window_set_icon(GTK_WINDOW(win), create_pixbuf("./res/web.png"));
    // gtk_window_set_icon_from_file(GTK_WINDOW(win), "./res/web.png", NULL);
    /* Enter the main loop */

    frame = gtk_fixed_new();

    gtk_container_add(GTK_CONTAINER(win), frame);

    plus = gtk_button_new_with_label("+");

    gtk_widget_set_size_request(plus, 80, 30);
    gtk_fixed_put(GTK_FIXED(frame), plus, 500, 20);

    minus = gtk_button_new_with_label("-");
    gtk_widget_set_size_request(minus, 80, 30);
    gtk_fixed_put(GTK_FIXED(frame), minus, 500, 80);

    label = gtk_label_new("0");

    gtk_fixed_put(GTK_FIXED(frame), label, 190, 58);

    gtk_widget_show_all(win);
    g_signal_connect_swapped(G_OBJECT(win), "destroy", G_CALLBACK(exit_app), NULL);

    g_signal_connect(plus, "clicked", G_CALLBACK(increase), label);
    g_signal_connect(minus, "clicked", G_CALLBACK(decrease), label);
    gtk_main ();
    return 0;
}
