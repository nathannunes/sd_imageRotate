//
// Created by Nathan Nunes on 10/1/22.
//
#include <iostream>
#include <vector>
#include "Rotator.h"
#include "ppm.h"
#include "pgm.h"
#include "PixelFiles/ColorPixel.h"

using namespace std;

vector<vector<ColorPixel> > Rotator::rotatePPM(vector<vector<ColorPixel> > imageContainer,Ppm inPpm){
    int maxH = inPpm.getMaxHeight();
    int maxW = inPpm.getMaxWidth();
    //Transposing matrix
    vector<vector<ColorPixel> > imageContainerT(maxW,vector<ColorPixel>(maxH));
    for(int i=0;i<inPpm.getMaxHeight();i++){
        for(int j=0;j<inPpm.getMaxWidth();j++){
            imageContainerT[j][i] = imageContainer[i][j];
        }
    }
    for(long long unsigned int i=0; i<imageContainerT.size(); ++i) {
        // 2 Pointer approach :  just like we do in 1D array we take left and right pointers
        // and swap the values and then make those pointers intersect at some point.
        int left = 0, right = imageContainerT[i].size()-1;
        while(left < right) {
            swap(imageContainerT[i][left], imageContainerT[i][right]);
            ++left;
            --right;
        }
    }
    return imageContainerT;
}

// get the instance
Rotator* Rotator::instance_ = NULL;
Rotator* Rotator::Instance() {
    if (instance_ == NULL) {
        instance_ = new Rotator();
    }
    return(instance_);
}

// The main function

int main(int argc, char** argv) {

    // get instance of rotator;
    Rotator *p1 = Rotator::Instance();


    string inputFile = argv[1];
    string outputFile = argv[2];
    string rotateDirection = argv[3];
    int angleOfRotation = atoi(argv[4]);
    const string PGM = "pgm";
    const string PPM = "ppm";

    // create objects of file types
    Ppm inPpm;
    Pgm inPgm;

    p1->setInputFile(inputFile);
    p1->setOutputFile(outputFile);
    p1->setRotateDirection(rotateDirection);

    //p1->setAngleOfRotation(angleOfRotation), p1->setRotateDirection(rotateDirection);

    if (inputFile.substr(inputFile.size() - 3) == PGM) {
        cout << "pgm file found" << endl;
        cout << inputFile;
        inPgm.readFile(p1->getInputFile() , p1->getOutputFile());
    } else if (inputFile.substr(inputFile.size() - 3) == PPM) {
        cout << "ppm file found" << endl;
        cout<< p1->getInputFile();
        inPpm.readFile(p1->getInputFile());
    } else { cout << "invalid input " << endl; }

    return 0;
}



