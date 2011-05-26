#include "formulae_textbox_widget.h"

int main (int argc, char *argv[]) {

  GtkWidget *window, *table, *entry;

  gtk_init(&argc, &argv);

  /* Creates main window */
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  initialize_window(window);
  gtk_widget_show(window);
  

  /* Creates a 1x2 table */
  table = gtk_table_new(1, 2, TRUE);
  gtk_container_add(GTK_CONTAINER (window), table);
  gtk_widget_show(table);

  /* Creates a textbox */
  entry = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY (entry),0);
  gtk_table_attach_defaults(GTK_TABLE (table),entry, 0, 1, 0, 1);
  gtk_widget_show(entry); 
  gtk_main();
  return 0;
}

