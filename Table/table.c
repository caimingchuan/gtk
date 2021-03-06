#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *table;
	GtkWidget *button;

	gchar *values[] = 
	{
		"7", "8", "9", "+",
		"4", "5", "6", "-",
		"1", "2", "3", "x",
		"0", ".", "=", "/",
	};

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	gtk_window_set_default_size(GTK_WINDOW(window), 800, 480);

	gtk_window_set_title(GTK_WINDOW(window), "table");

	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	table = gtk_table_new(4, 4, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(table), 2);

	gtk_container_add(GTK_CONTAINER(window), table);

	int i = 0;
	int j = 0;

	int pos = 0;
	
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			button = gtk_button_new_with_label(values[pos]);
			gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);
			pos++;
		}
	}
	

	gtk_widget_show_all(window);

	g_signal_connect_swapped(window, "destroy", gtk_main_quit, NULL);

	gtk_main();
	
	return 0;
}
