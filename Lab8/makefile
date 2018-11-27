# Programmer: Henry Hollis     Course: CSC112
# Assignment: lab8             Date: 11/8/2018

lab8: pixel.o driver.o
	g++ -o lab8 pixel.o driver.o
driver.o: driver.cpp colors.h
	g++ -Wall -pedantic -c driver.cpp
pixel.o: pixel.cpp pixel.h colors.h
	g++ -Wall -pedantic -c pixel.cpp
clean:
	\rm -f *.o lab8

