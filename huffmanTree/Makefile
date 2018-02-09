#
# Makefile
# main, huffmanTreeBuilder
#

CC = g++
CFlags = -c -std=c++11
pqDir = ../priorityQueue/
cfDir = ../characterFrequency/
stbDir = ../stringToBytes/


main: main.o stringToBytes.o huffmanTree.o characterFrequency.o priorityQueue.o
	$(CC) -o run main.o stringToBytes.o huffmanTree.o priorityQueue.o characterFrequency.o

main.o: main.cpp $(pqDir)priorityQueue.h $(cfDir)characterFrequency.h $(stbDir)stringToBytes.h
	$(CC) -I$(pqDir) -I$(cfDir) -I$(stbDir) $(CFlags) main.cpp

huffmanTree.o: huffmanTree.cpp $(pqDir)priorityQueue.h
	$(CC) -I$(pqDir) $(CFlags) huffmanTree.cpp

priorityQueue.o: $(pqDir)priorityQueue.cpp
	$(CC) $(CFlags) $(pqDir)priorityQueue.cpp

characterFrequency.o: $(cfDir)characterFrequency.cpp
	$(CC) $(CFlags) $(cfDir)characterFrequency.cpp

stringToBytes.o: $(stbDir)stringToBytes.cpp
	$(CC) $(CFlags) $(stbDir)stringToBytes.cpp

clean:
	rm -f *.o

all: main clean
