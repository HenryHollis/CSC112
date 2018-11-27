/**
* This class models the abstraction of a pixel with a C++ class.
* 
* @author Henry Hollis { @literal < hollhc17@wfu.edu >}
* @version 0.1 , Nov.9, 2018
 */
#include <iostream>
#include "pixel.h"

/**
 * @brief      Constructs the pixel object.
 *
 * @param[in]  r     { red value }
 * @param[in]  g     { green value }
 * @param[in]  b     { blue value }
 */
Pixel::Pixel(int r, int g, int b){

clip(r);
clip(g);
clip(b);	
red_ = r;
blue_ = b ;
green_ = g;
}




/**
 * @brief      Sets the red value.
 *
 * @param[in]  color  The color
 *
 * @return     { false if clipped, true if not }
 */
bool Pixel::setRed(int color){
	bool clipped = clip(color);
	red_ = color;
	return clipped;
}


/**
 * @brief      Sets the blue value.
 *
 * @param[in]  color  The color
 *
 * @return     { false if clipped, true if not  }
 */
bool Pixel::setBlue(int color){
	bool clipped = clip(color);
	blue_ = color;
	return clipped;
}


/**
 * @brief      Sets the green value.
 *
 * @param[in]  color  The color
 *
 * @return     { false if clipped, true if not }
 */
bool Pixel::setGreen(int color){
	bool clipped = clip(color);
	green_ = color;
	return clipped;
}


/**
 * @brief      calculates the grayscale value of a pixel
 *
 * @return     { the value }
 */
unsigned char Pixel::grayscale() const{
	unsigned char gray = (0.2989 * red_) + (0.5870*green_) + (0.1140 * blue_);
	return gray;

}

/**
 * @brief      { clips int to range 0-255 }
 *
 * @param      n     { int being clipped }
 *
 * @return     { false number was out of range, true if it was in range }
 */
bool Pixel::clip(int &n){
	if(n > 255){
		n =255;
		return false;
	}
	if(n < 0){
		n = 0; 
		return false;
	}
	return true;


}


/**
 * @brief     checks equality of two pixels
 *
 * @param[in]  rhs   The right hand side member
 *
 * @return     { true if equal, false if not }
 */
bool Pixel::operator==(const Pixel& rhs){
	if(green_ != rhs.green_)
		return false;
	if(blue_ != rhs.blue_)
		return false;
	if(red_ != rhs.red_)
		return false;
	return true;

}


/**
 * @brief      checks inequality of pixels
 *
 * @param[in]  rhs   The right hand side member
 *
 * @return     { true if not equal, false if equal }
 */
bool Pixel::operator!=(const Pixel& rhs){
	if(green_ == rhs.green_ && blue_ == rhs.blue_ && red_ == rhs.red_)
		return false;
	return true;

}


/**
 * @brief      adds similar color values between two pixels
 *
 * @param[in]  rhs   The right hand side pixel
 *
 * @return     { a new pixel whose color values are the sum of the old pixels }
 */
Pixel operator+(const Pixel& lhs, const Pixel& rhs){
	Pixel temp;
	int g = lhs.green_ + rhs.green_;
	int b = lhs.blue_ + rhs.blue_;
	int r = lhs.red_ + rhs.red_;
	temp.clip(g);
	temp.clip(b);
	temp.clip(r);
 	temp.green_ = g;
 	temp.blue_ = b;
 	temp.red_ = r;

	return temp;

}

/**
 * @brief      prints out pixel in colored format: [int, int, int]
 *
 * @param      out   The out stream
 * @param[in]  rhs   The right hand side member
 *
 * @return     { the out stream }
 */
ostream& operator<<(ostream& out, const Pixel& rhs){
	out << '[' << RED << (int)rhs.red_ <<".0" << NORM << ", ";
	out << GREEN << (int)rhs.green_ <<".0"<< NORM << ", ";
	out << BLUE << (int)rhs.blue_ <<".0"<< NORM << ']';
	return out;
}