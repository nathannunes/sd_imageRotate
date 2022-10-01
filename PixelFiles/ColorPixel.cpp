#include "ColorPixel.h"

ColorPixel::ColorPixel(int redValue, int greenValue, int blueValue){
    this->redValue=redValue;
    this->greenValue=greenValue;
    this->blueValue=blueValue;
}

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
