
/**
 * The header file for my pixel class, containing my fucntion prototypes.
 * 
 * @author Henry Hollis { @literal < hollhc17@wfu.edu >}
 * @version 0.1 , Nov.9, 2018
 */

#ifndef PIXEL_H
#define PIXEL_H
#include "colors.h"
using namespace std;

/*Pixel Class*/

class Pixel{  		

public:
	Pixel(int r = 255 , int g = 255, int b = 255);		//constructor, sets default values to 255, 255, 255

	//======Color getters=====

	unsigned char red() const;							
	unsigned char blue() const;
	unsigned char green() const;
	unsigned char grayscale() const;

	//======Color setters======

	bool setRed(int color);
	bool setBlue(int color);
	bool setGreen(int color);

	//====operation overloads=====

	bool operator==(const Pixel& rhs);
	bool operator!=(const Pixel& rhs);
	Pixel operator+(const Pixel& rhs);
	friend ostream& operator<<(ostream& out, const Pixel& rhs);

	bool clip(int& n); //clips values to range(0-255)
 

private:

	//====Private data members====
	unsigned char red_;
	unsigned char blue_;
	unsigned char green_;
};



#endif