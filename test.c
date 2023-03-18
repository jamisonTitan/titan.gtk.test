#include <gtk/gtk.h>

static void click_cb (GtkButton *btn) {
	g_print("Clickideedoo \n");
}

static void app_activate(GApplication *app) {
	GtkWidget *win;
	win = gtk_application_window_new (GTK_APPLICATION (app));
	GtkWidget *btn;
	gtk_window_set_title (GTK_WINDOW (win), "Test");
	gtk_window_set_default_size (GTK_WINDOW (win), 400, 300);

	btn = gtk_button_new_with_label("I fucken dare you");
	gtk_window_set_child(GTK_WINDOW (win), btn);
	g_signal_connect(btn, "clicked", G_CALLBACK(click_cb), NULL);

	gtk_window_present (GTK_WINDOW (win));
}

int main (int argc, char** argv) {
	GtkApplication *app;
	int stat;

	app = gtk_application_new("titan.gtk.test", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);
	stat = g_application_run(G_APPLICATION (app), argc, argv);
	g_object_unref (app);
	return stat;

}
