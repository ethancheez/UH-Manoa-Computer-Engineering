swap: swap.o swaptest.o
	cc swap.o swaptest.o -o swap

swapbig: swapbig.o swapbigdriver.o swap.o
	cc swapbig.o swapbigdriver.o swap.o -o swapbig

reorder: reorder.o reorderdriver.o swapbig.o swap.o
	cc reorder.o reorderdriver.o swapbig.o swap.o -o reorder

# dependency lines
swap.o: swap.h

swaptest.o: swap.h

swapbig.o: swap.h

reorder.o: swap.h

swapbigdriver.o: swap.h

reorderdriver.o: swap.h
