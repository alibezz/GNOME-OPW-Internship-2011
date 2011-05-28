#include "formulae_visualizer_text_entry.h"

GtkWidget *new_entry_with_buffer(const gchar *initial_chars, gint n_initial_chars) {
  GtkEntryBuffer *buffer = gtk_entry_buffer_new(initial_chars, n_initial_chars);
  GtkWidget *entry = gtk_entry_new_with_buffer(buffer);
  gtk_entry_buffer_set_max_length(buffer, BUFFER_MAX_LENGTH);

  /* TODO Verify the best way of erasing buffer (avoiding memory leaks) */
  return entry;
}
