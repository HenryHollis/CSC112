#include <iostream>
using namespace std;

class Pixel{
public:
int red() const;
int blue() const;
int green() const;

bool setRed(int color);
bool setBlue(int color);
bool setGreen(int color);

private:
unsigned char red_;
unsigned char blue_;
unsigned char green_;
}


int main(){

}


