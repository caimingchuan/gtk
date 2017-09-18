#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *vbox;

	GtkWidget *button1;
	GtkWidget *button2;
	GtkWidget *button3;
	GtkWidget *button4;
	GtkWidget *button5;
	
	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_default_size(GTK_WINDOW(window), 800, 480);

	gtk_window_set_title(GTK_WINDOW(window), "Vbox");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	gtk_container_border_width(GTK_CONTAINER(window), 5);

	vbox = gtk_vbox_new(TRUE, 1);

	gtk_container_add(GTK_CONTAINER(window), vbox);

	button1 = gtk_button_new_with_label("button1");
	
	button2 = gtk_button_new_with_label("button2");
	button3 = gtk_button_new_with_label("button3");
	button4 = gtk_button_new_with_label("button4");
	button5 = gtk_button_new_with_label("button5");

	gtk_box_pack_start(GTK_BOX(vbox), button1, TRUE, TRUE, 0);
	
	gtk_box_pack_start(GTK_BOX(vbox), button2, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button3, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button4, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button5, TRUE, TRUE, 0);

	gtk_widget_show_all(window);

	g_signal_connect_swapped(G_OBJECT(window), "destroy", gtk_main_quit, NULL);

	gtk_main();
	
	return 0;
}
