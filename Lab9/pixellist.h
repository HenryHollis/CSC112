/**
 * Header File for pixellist class
 * 
 * @author Henry Hollis { @literal < hollhc17@wfu.edu >}
 * @version 0.1, Nov.15, 2018
 */
#ifndef PIXELLIST_H
#define PIXELLIST_H	

#include <iostream>
#include "pixel.h"
using namespace std;

class PixelList{
public:

	PixelList(int size = 0, Pixel initPixel = Pixel());   //null constructor	

	PixelList(const PixelList& list);					  //copy constructor
	PixelList(Pixel pixel);								  //alternate constructor if only given a pixel
	~PixelList();										  //destructor

	int size() const { return size_ ; }					  //size getter

	void append(Pixel pixel = Pixel());					  //append a pixel to a pixellist object

	const PixelList& operator=( const PixelList& rhs);	  //overloaded assignment

	friend PixelList operator+(const PixelList& lhs, const PixelList& rhs);		//overloaded addition
	friend bool operator==( const PixelList& lhs, const PixelList& rhs);										//overloaded equality 
	friend bool operator!=( const PixelList& lhs, const PixelList& rhs);										//overloaded inequality
	friend ostream& operator<<(ostream& out, const PixelList& rhs); 			//overloaded output

private:
	Pixel* list_;		//array of pixel objects, dynamic
	int size_;			//number of pixels in list


};


#endif