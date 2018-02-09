#
# Makefile
# main, characterFreqeuncy
#

CC = g++
CFlags = -c -std=c++11

main: main.o characterFrequency.o
	$(CC) -o run main.o characterFrequency.o

main.o: main.cpp characterFrequency.h
	$(CC) $(CFlags) main.cpp

characterFrequency.o: characterFrequency.cpp characterFrequency.h
	$(CC) $(CFlags) characterFrequency.cpp

clean:
	rm -f *.o

all: main clean