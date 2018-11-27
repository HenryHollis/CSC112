# Programmer: Henry Hollis     Course: CSC112
# Assignment: lab9             Date: 11/13/2018

lab9: pixellist1.o pixellist2.o pixel.o driver.o
	g++ -o lab9 pixellist1.o pixellist2.o driver.o pixel.o

driver.o: driver.cpp colors.h
	g++ -Wall -pedantic -c driver.cpp

pixellist1.o: pixellist1.cpp pixellist.h colors.h pixel.h
	g++ -Wall -pedantic -c pixellist1.cpp

pixellist2.o: pixellist2.cpp pixellist.h colors.h pixel.h
	g++ -Wall -pedantic -c pixellist2.cpp
 
pixel.o: pixel.cpp pixel.h
	g++ -Wall -pedantic -c pixel.cpp
clean:
	\rm -f *.o lab9

