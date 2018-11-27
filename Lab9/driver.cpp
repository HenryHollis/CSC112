/** 
 * driver to test the pixel and pixellist classes. 
 * 
 * 
 * @author Henry Hollis { @literal < hollhc17@wfu.edu >}
 * @version 0.1, Nov.15, 2018
 */

#include<iostream>  
#include "pixel.h"  
#include "pixellist.h"
using namespace std;  

int main(){  

  cout<<CYAN<<"==============TESTING PIXELLIST CLASS=============="<<endl;
         cout<<"***************************************************\n"<<NORM;

  cout<<CYAN<<"\n=======Testing null and copy constructor===========\n"<<NORM;
 
  cout<<"PixelList list1(2, 1): ";
  PixelList list1(2, 1);
  cout<<list1<<endl;
  cout<<"PixelList list2(1, Pixel(1, 1, 1)): ";
  PixelList list2(2, Pixel(1, 1,1));
  cout<<list2<<endl;
  cout<<"PixelList list3(list1): ";
  PixelList list3(list1); // list2 is a copy of list1
  cout<<list3<<endl;

  cout<<CYAN<<"\n=============Testing append method=================\n"<<NORM;
  cout<<"list2 before: "<<list2<<endl;
  cout<<"list2.append(Pixel(8, 8, 8)): ";
  list2.append(Pixel(8, 8,8));
  cout<<list2<<endl;
  cout<<"list2.append(): ";
  list2.append();
  cout<<list2<<endl;

   cout<<CYAN<<"\n==============Testing size method=================\n"<<NORM;
   PixelList list4(3, Pixel(10, 10, 10));
  cout<<"List4: "<<list4<<endl;
  cout<<"List2: "<<list2<<endl;
  cout<<"size of list4: "<<list4.size()<<endl;
  cout<<"size of list2: "<<list2.size()<<endl;


  
  cout<<CYAN<<"\n=====Testing assignment overload and addition======\n"<<NORM;
  cout<<"List4: "<<list4<<endl;
  cout<<"List2: "<<list2<<endl;
  PixelList sum = list4 + list2;
  cout<<"Sum = list4 + list2, sum: "<<sum<<endl<<endl;
  cout<<"list4 again: ";
  cout<<list4<<endl;
  cout<<"List4 = List4 + Pixel(42), list4: ";
  list4 = list4 + Pixel(42);
  cout<<list4<<endl<<endl;
  cout<<"list2 again: ";
  cout<<list2<<endl;
  cout<<"Pixel(42, 0, 0) + list2: ";
  list2 = Pixel(42, 0, 0) + list2;
  cout<<list2<<endl;


  

  cout<<CYAN<<"\n==========Testing equality overloads===============\n"<<NORM;
  cout<<"Does list1 = list2? "<<(list1==list2)<<endl;
  cout<<"Does list1 = list1? "<<(list1==list1)<<endl;
  cout<<"Does list1 != list2? "<<(list1!=list2)<<endl;
  cout<<"Does list1 != list1? "<<(list1!=list1)<<endl;
  cout<<"Does Pixel() == list1? "<<(Pixel() == list1)<<endl;
  cout<<"Does Pixel(20, 1, 2) == Pixel(20,1 , 2)? "<<(Pixel(20, 1, 2) == Pixel(20,1 , 2))<<endl;


  return 0;  
   
}  

