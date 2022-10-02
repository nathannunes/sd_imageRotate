//
// Created by Nathan Nunes on 9/26/22.
//

#ifndef ASSIGNMENT_PGM_H
#define ASSIGNMENT_PGM_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "PixelFiles/grayPixel.h"

using namespace std;


using namespace std;

class Pgm {
public:
    Pgm();
    ~Pgm();
    int readFile(string filePath);


protected:

private:
    string magicNum;
    int maxHeight,maxWidth,maxPixelSize;
    vector<GrayPixel> grayPixelsVector;
    vector<vector<GrayPixel> > imageContainer;

};

#endif //ASSIGNMENT_PGM_H
