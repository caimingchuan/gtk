#include <gtk/gtk.h>

void frame_callback(GtkWindow *window, GdkEvent *event, gpointer data)
{
	int x, y, width, height;
	char buf[20];
	x = event->configure.x;
	y = event->configure.y;
	width =  event->configure.width;
	height =  event->configure.height;
	sprintf(buf, "%d, %d: %d, %d", x, y, width, height);
	gtk_window_set_title(window, buf);
}


int main(int argc, char *argv[])
{
	GtkWidget *window;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(window), "MovingWindow");

	gtk_window_set_default_size(GTK_WINDOW(window), 800, 480);
	
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	gtk_widget_add_events(window, GDK_CONFIGURE);

	g_signal_connect_swapped(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), G_OBJECT(window));
	g_signal_connect(G_OBJECT(window), "configure-event",G_CALLBACK(frame_callback), NULL);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
