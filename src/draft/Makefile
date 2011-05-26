OBJS = formulae_textbox_widget.o 
CFLAGS = `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -Wall -Wextra -g3

all: widget_draft

widget_draft: $(OBJS) main.c  
		gcc $(CFLAGS) $(OBJS) main.c -o draft 

clean:
	rm -f $(OBJS) t

.PHONY: all clean


