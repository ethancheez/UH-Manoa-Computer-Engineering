averages: fill.o print.o average.o matchingElements.o averages.o printLarger.o printSmaller.o largerElements.o smallerElements.o
	cc fill.o print.o average.o matchingElements.o averages.o printLarger.o printSmaller.o largerElements.o smallerElements.o -o averages

water: meter.o water.o reading.o 
	cc meter.o water.o reading.o -o water2

# dependency lines
fill.o: table.h

print.o: table.h

average.o: table.h

matchingElements.o: table.h

averages.o: table.h

printLarger.o: table.h

printSmaller.o: table.h

largerElements.o: table.h

smallerElements.o: table.h

meter.o: meter.h water.h

water.o: meter.h water.h reading.h

reading.o: reading.h water.h
