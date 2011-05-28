#ifndef FORMULAE_VISUALIZER_TEXT_ENTRY
#define FORMULAE_VISUALIZER_TEXT_ENTRY

#include <gtk/gtk.h>
#define BUFFER_MAX_LENGTH 3000

GtkWidget *new_entry_with_buffer(const gchar *initial_chars, gint n_initial_chars);

#endif

