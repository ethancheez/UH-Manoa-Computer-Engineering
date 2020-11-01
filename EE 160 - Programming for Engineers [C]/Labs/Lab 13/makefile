all: averages water

averages: util.o averages.o
	cc util.o averages.o -o averages

water: meter.o water.o reading.o 
	cc meter.o water.o reading.o -o water2

# dependency lines
util.o: util.h

averages.o: util.h


meter.o: meter.h water.h

water.o: meter.h water.h reading.h

reading.o: reading.h water.h


clean:
	rm *.o
	rm averages
	rm water2