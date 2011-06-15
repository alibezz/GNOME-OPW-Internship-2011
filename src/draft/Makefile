OBJS = formulae_visualizer_window.o formulae_visualizer_combo_boxes.o formulae_visualizer_text_entry.o

CFLAGS = `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -Wall -Wextra -g3

all: widget_draft

widget_draft: $(OBJS) main.c  
		gcc $(CFLAGS) $(OBJS) main.c -o draft

clean:
	rm -f $(OBJS) 

.PHONY: all clean


