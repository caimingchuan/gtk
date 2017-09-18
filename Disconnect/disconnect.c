#include <gtk/gtk.h>

int handler_id;

void button_clicked(GtkWidget *widget, gpointer data)
{
	g_print("clicked\n");
}

void toggle_signal(GtkWidget *widget, gpointer window)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
	{
		
		handler_id = g_signal_connect(G_OBJECT(window), "clicked", G_CALLBACK(button_clicked), NULL);
	}
	else
	{
		g_signal_handler_disconnect(window, handler_id);
	}
}

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *fixed;
	GtkWidget *button;
	GtkWidget *check;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_default_size(GTK_WINDOW(window), 800, 480);

	gtk_window_set_title(GTK_WINDOW(window), "disconnect");

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	fixed = gtk_fixed_new();

	gtk_container_add(GTK_CONTAINER(window), fixed);

	button = gtk_button_new_with_label("Click");

	
	
	return 0;
}
