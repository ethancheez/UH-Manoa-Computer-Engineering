list: main.o node.o list.o
	g++ main.o node.o list.o -o list1

main.o: list.hpp
node.o: node.hpp
list.o: node.hpp list.hpp




clean:
	rm -rf *.o
	rm -f list1
