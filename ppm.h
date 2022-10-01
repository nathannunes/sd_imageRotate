#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "PixelFiles/ColorPixel.h"
using namespace std;

#ifndef PPM_H
#define PPM_H

class Ppm
{
public:
    Ppm();
    ~Ppm();
    int readFile(string filePath);


protected:

private:
    string magicNum;
    int maxHeight,maxWidth,maxPixelSize;
    vector<ColorPixel> colorPixelsVector;
    vector<vector<ColorPixel> > imageContainer;
};

#endif // PPM_H
