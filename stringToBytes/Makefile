#
# Makefile
# main, stringToByte
#


CC = g++
CFlags = -c -std=c++11

main: main.o stringToBytes.o
	$(CC) -o run main.o stringToBytes.o

main.o: main.cpp stringToBytes.h
	$(CC) $(CFlags) main.cpp

stringToBytes.o: stringToBytes.cpp
	$(CC) $(CFlags) stringToBytes.cpp

clean:
	rm -f *.o

all: main clean
