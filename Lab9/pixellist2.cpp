/**
 * overloaded function definitions for the pixellist class
 * 
 * @author Henry Hollis { @literal < hollhc17@wfu.edu >}
 * @version 0.1, Nov.15, 2018
 */
#include <cassert>
#include "pixellist.h"

using namespace std;


/**
 * @brief      overloaded assignment for pixellist class
 *
 * @param[in]  rhs   the pixellist that is being assigned
 *
 * @return     { another pixellist  }
 */
const PixelList& PixelList::operator=( const PixelList& rhs){

	if(this != &rhs){					//if the calling object is different from the one being assigned...

		if(list_) delete [] list_ ;		//delete calling object list_
		size_ = rhs.size_ ;

		if(rhs.size_ > 0){				//if the object being assigned has size...

			list_ = new (nothrow) Pixel[rhs.size_];		//calling object gets new list
			assert(list_);

			for(int i = 0; i < rhs.size_; i++)
				list_[i] = rhs.list_[i];				//calling object's list populated
 		}
	else
		list_ = 0;
 	}

 return *this;


}


/**
 * @brief      overloaded addition, can symmetrically add two pixel lists element by element.
 *
 * @param[in]  lhs   The left hand side pixellist
 * @param[in]  rhs   The right hand side pixellist
 *
 * @return     { the "sum" of the pixellists }
 */
PixelList operator+(const PixelList& lhs, const PixelList& rhs){

	if(lhs.size_ > rhs.size_){			//if lhs is bigger...
		PixelList temp(lhs.size_);

		for(int i = 0; i < lhs.size_ ; i++)					//assign lhs list to temp list
			temp.list_[i] = lhs.list_[i];
		for(int i = 0; i < rhs.size_; i++)
			temp.list_[i] = temp.list_[i] + rhs.list_[i];	//assign rhs + lhs to temp list
		return temp;
	}
	else{											//if rhs is >= lhs, do the same thing but switch lists
		PixelList temp(rhs.size_);

		for(int i = 0; i < rhs.size_ ; i++)
			temp.list_[i] = rhs.list_[i];
		for(int i = 0; i < lhs.size_; i++)
			temp.list_[i] = temp.list_[i] + lhs.list_[i];
		return temp;

	}

}


/**
 * @brief      overloaded output
 *
 * @param      out   The output stream
 * @param[in]  rhs   The right hand side pixellist
 *
 * @return     { output stream }
 */
ostream& operator<<(ostream& out, const PixelList& rhs){
	cout<<'{';
	for(int i = 0; i < rhs.size_-1; i++)
		cout<<rhs.list_[i]<<", ";			//pixel class handles output of pixel so no need to rewrite coloring or formating for that
	cout<<rhs.list_[rhs.size_-1]<<'}';

	return out;

}



/**
 * @brief      overloaded equality operator
 *
 * @param[in]  lhs   The left hand side pixellist
 * @param[in]  rhs   The right hand side pixellist
 *
 * @return     { true if every pixel is equivalent, false otherwise }
 */
bool operator==(  const PixelList& lhs, const PixelList& rhs){
	if(lhs.size_ != rhs.size_)
		return false;
	for(int i = 0; i < lhs.size_; i++){
		if(lhs.list_[i] != rhs.list_[i])
			return false;
	}
	return true;

}



/**
 * @brief      overloaded inequality operator
 *
 * @param[in]  lhs   The left hand side pixellist
 * @param[in]  rhs   The right hand side pixellist
 *
 * @return     { true if not every pixel is equal, false if they are exactly equal  }
 */
bool operator!=( const PixelList& lhs, const PixelList& rhs){
	if(lhs.size_ != rhs.size_)
		return true;
	for(int i = 0; i < lhs.size_; i++){
		if(lhs.list_[i] != rhs.list_[i])
			return true;
	}
	return false;

}

