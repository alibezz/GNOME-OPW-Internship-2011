#include "formulae_visualizer_combo_boxes.h"

void cb_changed( GtkComboBoxText *combo, GtkEntryBuffer *buffer) {
  gchar *string = gtk_combo_box_text_get_active_text( combo );
  gtk_entry_buffer_insert_text(buffer, gtk_entry_buffer_get_length(buffer), string, -1);
  g_free( string );
}

/*TODO Refactor it: number of params must be flexible and must be regulated by a xml */
GtkWidget *new_combo_box_with_text(const gchar *text1, const gchar *text2, const gchar *text3) {
  GtkWidget *combo = gtk_combo_box_text_new();
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "0", text1 );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "1", text2 );
  gtk_combo_box_text_append( GTK_COMBO_BOX_TEXT( combo ), "2", text3 );

  gtk_widget_set_can_focus(GTK_WIDGET(combo), TRUE);
  gtk_widget_activate(combo);

  AtkObject *obj;
  obj = gtk_widget_get_accessible(combo);
  atk_object_set_name(obj, "Preferences");
  atk_object_set_role(obj, ATK_ROLE_LIST);
  if (gtk_widget_get_can_focus(combo)) {
    puts("should have ATK_STATE_FOCUSABLE");
  } else {
    puts("bug");
  }


/*  AtkStateSet *states = atk_object_ref_state_set(obj);
  gboolean included_state = atk_state_set_add_state(states, ATK_STATE_FOCUSABLE);
  atk_object_notify_state_change(obj, ATK_STATE_FOCUSABLE, TRUE);
  atk_object_notify_state_change(obj, ATK_STATE_FOCUSABLE, FALSE); */
 
  return combo;
}
