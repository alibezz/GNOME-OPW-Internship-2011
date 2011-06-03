#include "formulae_visualizer_combo_boxes.h"
#include "formulae_visualizer_text_entry.h"
#include "formulae_visualizer_window.h"

int main (int argc, char *argv[]) {

  /*FIXME  Clean this main */

  GtkWidget *window, *entry, *grid, *combo1, *combo2, *combo3, *frame;
  gtk_init(&argc, &argv);

  /* Creates main window */
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  initialize_window(window);
  
  /* Creates a grid */
  grid = gtk_grid_new ();
  gtk_container_add(GTK_CONTAINER(window), grid);

  /* Creates a text entry and attaches to grid */
  entry = new_entry_with_buffer(NULL, 0); 
  GtkEntryBuffer *buffer = gtk_entry_get_buffer((GtkEntry *)entry);
  gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 3, 1);

  /*FIXME Regulate paramaters via xml */
  /* Creates favorite bands' combo and attaches to grid */
  combo1 = new_combo_box_with_text("Velvet Underground", "Joy Division", "My Bloody Valentine");
  g_signal_connect( G_OBJECT(combo1), "changed", G_CALLBACK( cb_changed ), GTK_ENTRY_BUFFER(buffer));
  frame = gtk_frame_new("Operators");
  gtk_container_add(GTK_CONTAINER(frame), combo1);
  gtk_grid_attach(GTK_GRID(grid), frame, 0, 1, 1, 1);

  /* Creates favorite foods' combo and attaches to grid */
  combo2 = new_combo_box_with_text("Mexican", "Japanese", "Italian");
  g_signal_connect( G_OBJECT(combo2), "changed", G_CALLBACK( cb_changed ), GTK_ENTRY_BUFFER(buffer));
  frame = gtk_frame_new("Delimiters");
  gtk_container_add(GTK_CONTAINER(frame), combo2);
  gtk_grid_attach(GTK_GRID(grid), frame, 1, 1, 1, 1);

  /* Creates favorite movies' combo and attaches to grid */
  combo3 = new_combo_box_with_text("Dekalog", "Acossado", "Magnolia");
  g_signal_connect( G_OBJECT(combo3), "changed", G_CALLBACK( cb_changed ), GTK_ENTRY_BUFFER(buffer));
  frame = gtk_frame_new("Other symbols");
  gtk_container_add(GTK_CONTAINER(frame), combo3);
  gtk_grid_attach(GTK_GRID(grid), frame, 2, 1, 1, 1);

  /* Shows all widgets recursively */
  gtk_widget_show_all(window); 
  gtk_main();
  return 0;
}

