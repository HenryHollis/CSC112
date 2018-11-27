# Programmer: Henry Hollis     Course: CSC112
# Assignment: lab7             Date: 11/01/2018

lab7: main.o words.o stemming.o
	g++ -o lab7 main.o words.o stemming.o
main.o: main.cpp words.h
	g++ -Wall -pedantic -c main.cpp
words.o: words.cpp words.h
	g++ -Wall -pedantic -c words.cpp
stemming.o: stemming.cpp stemming.h
	g++ -Wall -pedantic -c stemming.cpp
clean:
	\rm -f *.o lab7

