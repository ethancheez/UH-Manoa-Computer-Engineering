play: play.o menu.o display.o
	cc play.o menu.o display.o -o game -lncurses

play.o: menu.h display.h

menu.o: menu.h


clean:
	rm play.o
	rm menu.o
	rm game