#ifndef FORMULAE_VISUALIZER_COMBO_BOXES
#define FORMULAE_VISUALIZER_COMBO_BOXES

#include <gtk/gtk.h>
#include <atk/atk.h>

void cb_changed( GtkComboBoxText *combo, GtkEntryBuffer *buffer);
GtkWidget *new_combo_box_with_text(const gchar *text1, const gchar *text2, const gchar *text3);

#endif

