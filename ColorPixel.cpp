// Assignment by Nathan Nunes , Rajat Pandey
#include "ColorPixel.h"

ColorPixel::ColorPixel(int redValue, int greenValue, int blueValue){
    this->redValue=redValue;
    this->greenValue=greenValue;
    this->blueValue=blueValue;
}

ColorPixel::ColorPixel(unsigned char binRed,unsigned char binGreen,unsigned char binBlue){
    this->binRed=binRed;
    this->binGreen=binGreen;
    this->binBlue=binBlue;
}

ColorPixel::ColorPixel(){}

ColorPixel::~ColorPixel()
{
    //dtor
}

int ColorPixel::getRedValue(){

    return this->redValue;
}

int ColorPixel::getGreenValue(){

    return this->greenValue;
}

int ColorPixel::getBlueValue(){

    return this->blueValue;
}

unsigned char ColorPixel::getBinRed(){
    return this->binRed;
}

unsigned char ColorPixel::getBinGreen(){
    return this->binGreen;
}

unsigned char ColorPixel::getBinBlue(){
    return this->binBlue;
}
