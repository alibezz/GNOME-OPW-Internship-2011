#include "formulae_textbox_widget.h"
#define BUFFER_MAX_LENGTH 3000

static void combo_changed( GtkComboBoxText *combo, GtkEntryBuffer *buffer) {
    gchar *string = gtk_combo_box_text_get_active_text( combo );
 
    /* Prints it to the console - if nothing is selected, print NULL */
    g_print( "Selected (simple): >> %s <<\n", ( string ? string : "NULL" ) );
    
   /* Appends string to buffer */
   gtk_entry_buffer_insert_text(buffer, gtk_entry_buffer_get_length(buffer), string, -1);
    /* Frees string */
    g_free( string );
}

GtkWidget *new_entry_with_buffer(const gchar *initial_chars, gint n_initial_chars) {
  GtkEntryBuffer *buffer = gtk_entry_buffer_new(initial_chars, n_initial_chars); 
  GtkWidget *entry = gtk_entry_new_with_buffer(buffer);
  gtk_entry_buffer_set_max_length(buffer, BUFFER_MAX_LENGTH);

  /* TODO Verify the best way of erasing buffer (avoiding memory leaks) */
  return entry; 
}


/*TODO Refactor it: number of params must be flexible and must be regulated by a xml */

GtkWidget *new_combo_box_with_text(const gchar *text1, const gchar *text2, const gchar *text3) {
  GtkWidget *combo = gtk_combo_box_text_new();
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "0", text1 );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "1", text2 );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "2", text3 );
  
  return combo;
}

int main (int argc, char *argv[]) {

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

  /* Creates favorite bands' combo and attaches to grid */
  combo1 = new_combo_box_with_text("Velvet Underground", "Joy Division", "My Bloody Valentine");
  g_signal_connect( G_OBJECT(combo1), "changed", G_CALLBACK( combo_changed ), GTK_ENTRY_BUFFER(buffer));
  frame = gtk_frame_new("Favorite Bands");
  gtk_container_add(GTK_CONTAINER(frame), combo1);
  gtk_grid_attach(GTK_GRID(grid), frame, 0, 1, 1, 1);

  /* Creates favorite foods' combo and attaches to grid */
  combo2 = new_combo_box_with_text("Mexican", "Japanese", "Italian");
  g_signal_connect( G_OBJECT(combo2), "changed", G_CALLBACK( combo_changed ), GTK_ENTRY_BUFFER(buffer));
  frame = gtk_frame_new("Favorite Foods");
  gtk_container_add(GTK_CONTAINER(frame), combo2);
  gtk_grid_attach(GTK_GRID(grid), frame, 1, 1, 1, 1);

  /* Creates favorite movies' combo and attaches to grid */
  combo3 = new_combo_box_with_text("Dekalog", "Acossado", "Magnolia");
  g_signal_connect( G_OBJECT(combo3), "changed", G_CALLBACK( combo_changed ), GTK_ENTRY_BUFFER(buffer));
  frame = gtk_frame_new("Favorite Movies");
  gtk_container_add(GTK_CONTAINER(frame), combo3);
  gtk_grid_attach(GTK_GRID(grid), frame, 2, 1, 1, 1);

  /* Shows all widgets recursively */
  gtk_widget_show_all(window); 
  gtk_main();
  return 0;
}

