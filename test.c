#include <gtk/gtk.h>

int main (int arc, char** argv) {
	GTKApplication *app;
	int stat;

	app = gtk_application_new("titan.gtk.test", G_APPLICATION_FLAGS_NONE);
	stat = g_application_run(G_APPLICATION (app), argc, argv);
	g_object_unref (app);
	return stat;

}
