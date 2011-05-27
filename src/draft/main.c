#include "formulae_textbox_widget.h"
#include <string.h>
#define BUFFER_MAX_LENGTH 3000

static void cb_changed( GtkComboBoxText *combo, GtkEntryBuffer *buffer) {
    gchar *string = gtk_combo_box_text_get_active_text( combo );
 
    /* Prints it to the console - if nothing is selected, print NULL */
    g_print( "Selected (simple): >> %s <<\n", ( string ? string : "NULL" ) );
    
   /* Appends string to buffer */
   gtk_entry_buffer_insert_text(buffer, gtk_entry_buffer_get_length(buffer), string, -1);
    /* Frees string */
    g_free( string );
}


int main (int argc, char *argv[]) {

  GtkWidget *window, *table, *entry, *grid, *combo, *frame;
  GtkEntryBuffer *buffer;

  gtk_init(&argc, &argv);

  /* Creates main window */
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  initialize_window(window);
  

  /* Creates a 1x1 table and attaches a textbox on it */
  table = gtk_table_new(1, 1, TRUE);
 
  buffer = gtk_entry_buffer_new(NULL, 0); 
  entry = gtk_entry_new_with_buffer(buffer);
  gtk_entry_buffer_set_max_length(buffer, BUFFER_MAX_LENGTH);
  
  gtk_entry_set_max_length(GTK_ENTRY (entry),0);
  gtk_table_attach_defaults(GTK_TABLE (table),entry, 0, 1, 0, 1); 


  /* Creates a combobox */
  combo = gtk_combo_box_text_new();
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "0", "" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "1", "Velvet" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "2", "Joy Division" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "3", "Jesus and Mary Chain" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "4", "My Bloody Valentine" );

  /* Puts the combobox in a frame */
  frame = gtk_frame_new("Favorite Bands");
  gtk_container_add(GTK_CONTAINER(frame), combo);

  /* Creates a grid */
  grid = gtk_grid_new ();
  gtk_container_add(GTK_CONTAINER(window), grid);

  /* And adds the table */
  gtk_grid_attach(GTK_GRID(grid), table, 0, 0, 3, 1);

  /* And adds the frame */
  gtk_grid_attach(GTK_GRID(grid), frame, 0, 1, 1, 1);

 /* Creates another combobox */
  combo = gtk_combo_box_text_new();
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "0", "" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "1", "Mexican" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "2", "Chinese" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "3", "Japanese" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "4", "Italian" );

  /* Puts the combobox in a frame */
  frame = gtk_frame_new("Favorite Foods");
  gtk_container_add(GTK_CONTAINER(frame), combo);

  /* And adds new frame to grid */
  gtk_grid_attach(GTK_GRID(grid), frame, 1, 1, 1, 1);

 /* Creates another combobox */
  combo = gtk_combo_box_text_new();
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "0", "" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "1", "Dekalog" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "2", "Cleo de 5 a 7" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "3", "Acossado" );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "4", "Magnolia" );

  /* Puts the combobox in a frame */
  frame = gtk_frame_new("Favorite Movies");
  gtk_container_add(GTK_CONTAINER(frame), combo);

  /* And adds new frame to grid */
  gtk_grid_attach(GTK_GRID(grid), frame, 2, 1, 1, 1);

  /* Connects a handler to last combobox */
  g_signal_connect( G_OBJECT( combo ), "changed", G_CALLBACK( cb_changed ), GTK_ENTRY_BUFFER(buffer));
 

  /* Shows all widgets recursively */
  gtk_widget_show_all(window); 
  gtk_main();
  return 0;
}

