

ROMAN = /inst/ee/ee160/ee160/Code.lect/Roman
CHAP4 = /inst/ee/ee160/ee160/Code.text/Chap4

roman: driver.o roman.o romanutil.o
	cc driver.o roman.o romanutil.o -o roman

driver.o: roman.h

roman.o: roman.h romanutil.h

romanutil.o: roman.h romanutil.h tfdef.h chrutil.h

links:
	ln -f -s $(ROMAN)/roman.c .
	ln -f -s $(ROMAN)/roman.h .
	ln -f -s $(ROMAN)/romanutil.c .
	ln -f -s $(ROMAN)/romanutil.h .
	ln -f -s $(ROMAN)/driver.c .
	ln -f -s $(CHAP4)/chrutil.h .
	ln -f -s $(CHAP4)/tfdef.h .

clean: 
	rm *.o

real_clean: clean
	rm roman

