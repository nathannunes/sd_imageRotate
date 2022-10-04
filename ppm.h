#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "ColorPixel.h"
using namespace std;

#ifndef PPM_H
#define PPM_H

class Ppm
{
public:
    Ppm();
    ~Ppm();
    vector<vector<ColorPixel> > readFile(string filePath);
    void writeFile(vector<vector<ColorPixel> > imageContainerT);
    int getMaxHeight();
    int getMaxWidth();
    string getMagicNum();
	void swapDimensions(){
        swap(this->maxHeight,this->maxWidth);
    }


protected:

private:
    string magicNum;
    int maxHeight,maxWidth,maxPixelSize;
    vector<ColorPixel> colorPixelsVector;
    vector<vector<ColorPixel> > imageContainer;
};

#endif // PPM_H
