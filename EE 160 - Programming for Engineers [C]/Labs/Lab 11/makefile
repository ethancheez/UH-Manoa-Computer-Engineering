# makefile for Lab 11

# target to create all executables for this lab
all: trig

#complete the dependency and action lines for the following targets

# Problem 2 - cos()
trig: driver1.o trig.o util.o exponent.o
	cc driver1.o trig.o util.o exponent.o -o trig

# source file dependencies
#  You should fill these in and add any additional targets you need

driver1.o: trig.h util.h exponent.h

trig.o: trig.h util.h exponent.h

util.o: util.h

exponent.o: exponent.h


# utility targets

clean:
	rm  -f *.o
        
real_clean: clean
	rm  -f trig a.out core