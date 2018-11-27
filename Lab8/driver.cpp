/** 
 *  @file driver.cpp
 *  @brief CSC 112, Lab 8, driver program  
 *
 *  This program tests the Pixel class, enjoy... 
 *  
 *  @author Nomed Nocaed (nnocae10)
 *  @date	11/2/2018  
 *  @bug	No known bugs.
 */

#include<iostream>  
#include "pixel.h"  
using namespace std;  

int main(){  
   cout << "========= constructor and accessor tests ======== \n";  
   
   Pixel p1;  
   Pixel p2(10, 20);  
   Pixel p3(10, 20, 30);  
   // note the casting...  
   cout << "p1 (255, 255, 255): " << (int) p1.red() << ' ' << (int) p1.green() 
		  << ' ' << (int) p1.blue() << '\n';  
   cout << "p2 (10, 20, 255): " << (int) p2.red() << ' ' << (int) p2.green() 
        << ' ' << (int) p2.blue() << '\n';  
   cout << "p3 (10, 20, 30): " << (int) p3.red() << ' ' << (int) p3.green() 
        << ' ' << (int) p3.blue() << '\n';  

   cout << "======== setRed, setGreen, setBlue tests ======== \n";  
   bool first = p1.setRed(18);  
   bool second = p1.setGreen(-20);  
   bool third = p1.setBlue(270);  
   cout << "p1 (18, 0, 255): " << (int) p1.red() << ' ' << (int) p1.green() 
        << ' ' << (int) p1.blue() << '\n';  
   cout << "results of the set functions (1, 0, 0) " << first << ' '  
        << second << ' ' << third << '\n';  

	
   cout << "================= grayscale test ================ \n";  
   cout << "p3 (18): " << (int) p3.grayscale() << '\n';  


   cout << "================== output tests ================= \n";  
   cout << "p1: " << p1 << '\n';  
   cout << "p2: " << p2 << '\n';  
   cout << "p3: " << p3 << '\n';  

   cout << "=================== logic tests ================= \n";  
   cout << "p1 == p2: " << (p1 == p2) << '\n';  
   cout << "p1!== p2: " << (p1 != p2) << '\n';  
   cout << "p1 == p1: " << (p1 == p1) << '\n';  

   cout << "=============== operator+ tests ================= \n";  
   cout << "p1 + p2: " << p1 + p2 << '\n';  
   cout << "p2 + p3: " << p2 + p3 << '\n';  
   cout << "p1 + p2 + Pixel(255, 255, 255): " << p1 + p2 + Pixel(255, 255, 255)
        << '\n';  

   cout << "============== output tests again =============== \n";  
   cout << "p1: " << p1 << '\n';  
   cout << "p2: " << p2 << '\n';  
   cout << "p3: " << p3 << '\n';  

   return 0;  
   
}  

