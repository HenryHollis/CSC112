/**
 *
 *Half of the picellist class' function definitions. Function overloads are located in pixellist2.cpp
 *
 * @author Henry Hollis { @literal < hollhc17@wfu.edu >}
 * @version 0.1, Nov.15, 2018
 */

#include <cassert>
#include "pixellist.h"

using namespace std;

/**
 * @brief      null constructor for the pixellist class
 *
 * @param[in]  initPixel  The default pixel (255, 255, 255)
 * @param[in]  size       The default size (0)
 */
PixelList:: PixelList(int size, Pixel initPixel){ 
	if(size > 0){								//if user wants an array with size...
		list_ = new (nothrow) Pixel[size];		//create dynamic array of "size" elements and set to list_ member
		assert(list_);							//error checking
		size_ = size;							//set pixellist objects size_ member to user specified "size"

		for(int i = 0; i < size_; i++)			//for every element of pixel list...
			list_[i] = initPixel;				//populate pixellist object's list member with default pixels	
	}
	else {										//if array has no size...
		list_ = NULL;							//park the pointer
		size_ = 0;								//set size_ member to 0
	}
}


/**
 * @brief      constructs the object given a single pixel object
 *
 * @param[in]  pixel  The pixel
 */
PixelList::PixelList(Pixel pixel){

	list_ = new (nothrow) Pixel[1];	//new array of 1
	assert(list_);					//error checking
	list_[0] = pixel;				//first element in list is pixel supplied by argument
	size_ = 1;						//list is 1 long

}


/**
 * @brief      copy constructor
 *
 * @param[in]  original  The original pixellist object
 */
PixelList::PixelList(const PixelList& original){  

	if(original.size_ > 0){								//if the object being copied has size...

		list_ = new (nothrow) Pixel[original.size_];	//make dynamic array of original.object.size_ pixels and assign it to copy's list_ member
		assert(list_);									//error checking
		size_ = original.size_;							//assign the copy's size_ to original's size_

		for(int i = 0; i < size_ ; i++)					//create a deep copy by populating the new object's list_ with the original object's list_
			list_[i] = original.list_[i];
	}
	else {												//if the object neing copied has no size...
		list_ = NULL;									//park the list_ pointer
		size_ = 0;										//set copy's size to 0
	}
	
}


/**
 * @brief      Destroys the object.
 */
PixelList::~PixelList(){
	if(list_)				//if list_ points to something...
		delete [] list_ ;	//free memory


}


/**
 * @brief      appends a pixel object to the end of pixellist object
 *
 * @param[in]  pixel  The pixel being appended
 */
void PixelList::append(Pixel pixel){ 
	Pixel* temp = new ( nothrow ) Pixel[size_ + 1];		//create temp dynamic array, 1 bigger than list_ was
	assert(temp);										//error checking

	for( int i = 0; i < size_ ; i ++)					//copy old list_ to the new templist
		temp[i] = list_[i];

	temp[size_ ] = pixel;								//assign the last element of templist as the pixel
	size_++;											//set pixellist's size as one bigger for this next step...

	if(list_) delete [] list_ ;							//if pixellist's list_ is not null, delete it. to avoid mem leak
 	list_ = temp;										//assign templist to pixellist's list_ member

}