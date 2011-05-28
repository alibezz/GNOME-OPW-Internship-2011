#include "formulae_visualizer_window.h"

void initialize_window(GtkWidget *window) {
  gtk_window_set_title(GTK_WINDOW(window),"Formulae Textbox Widget");
  g_signal_connect(window, "destroy",G_CALLBACK (gtk_main_quit), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);
}
                                                
