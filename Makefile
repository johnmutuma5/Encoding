#
# Makefile
# main.cpp
#

CC = g++
CFlags = -c -std=c++11


hfmDir = ./huffmanTree/
pqDir = ./priorityQueue/
cfDir = ./characterFrequency/
stbDir = ./stringToBytes/


main: main.o encoder.o huffmanTree.o characterFrequency.o stringToBytes.o
	$(CC) -o run main.o encoder.o huffmanTree.o characterFrequency.o stringToBytes.o

main.o: main.cpp encoder.h
	$(CC) -I$(hfmDir) -I$(pqDir) $(CFlags) main.cpp

encoder.o: encoder.cpp encoder.h $(hfmDir)huffmanTree.h $(cfDir)characterFrequency.h $(stbDir)stringToBytes.h
	$(CC) -I$(hfmDir) -I$(pqDir) -I$(cfDir) -I$(stbDir) $(CFlags) encoder.cpp

huffmanTree.o: $(hfmDir)huffmanTree.cpp $(pqDir)priorityQueue.h
	$(CC) -I$(pqDir) $(CFlags) $(hfmDir)huffmanTree.cpp

characterFrequency.o: $(cfDir)characterFrequency.cpp $(cfDir)characterFrequency.h
	$(CC) $(CFlags) $(cfDir)characterFrequency.cpp

stringToBytes.o: $(stbDir)stringToBytes.cpp $(stbDir)stringToBytes.h
	$(CC) $(CFlags) $(stbDir)stringToBytes.cpp

clean:
	rm -f *.o

all: main clean