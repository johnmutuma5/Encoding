#
# Makefile
# main.cpp
#

main: main.o
	g++ -o run main.o

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

clean:
	rm -f *.o

all: main clean