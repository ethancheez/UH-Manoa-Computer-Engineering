all: driver1 driver2 driver3 datediff

driver1: leap.o
	cc leap.o driver1.c -o driver1

driver2: days.o leap.o
	cc days.o leap.o driver2.c -o driver2

driver3: julian.o days.o leap.o
	cc julian.o days.o leap.o driver3.c -o driver3

datediff: julian.o days.o leap.o
	cc julian.o days.o leap.o datediff.c -o datediff

days.o: days.h

leap.o: leap.h

julian.o: julian.h

clean:
	rm *.o
	rm driver1
	rm driver2
	rm driver3
	rm datediff
