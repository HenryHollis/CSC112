# Programmer: Henry Hollis     Course: CSC112
# Assignment: lab6             Date: 10/30/2018

lab6: main.o words.o
	g++ -o lab6 main.o words.o
main.o: main.cpp words.h
	g++ -Wall -pedantic -c main.cpp
words.o: words.cpp words.h
	g++ -Wall -pedantic -c words.cpp

clean:
	\rm -f *.o lab6

