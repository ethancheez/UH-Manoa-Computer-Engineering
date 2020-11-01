all: driver1 driver2 countgrades

driver1: mygrader.o
	cc mygrader.o driver1.c -o driver1

driver2: mygrader2.o
	cc mygrader2.o driver2.c -o driver2

countgrades:
	cc countgrades.c -o countgrades

mygrader.o: mygrader.h

mygrader2.o: mygrader2.h


clean:
	rm *.o
	rm driver1
	rm driver2
	rm countgrades