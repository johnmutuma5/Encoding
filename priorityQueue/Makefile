#
# Makefile
# main.cpp
#

C = g++
CFlags = -c -std=c++11



main: main.o priorityQueue.o
	$(C) -o run main.o priorityQueue.o

main.o: main.cpp priorityQueue.h
	$(C) $(CFlags) main.cpp

priorityQueue.o: priorityQueue.cpp priorityQueue.h
	$(C) $(CFlags) priorityQueue.cpp

clean:
	rm -f *.o

all: main clean