//
// Created by Nathan Nunes on 10/2/22.
//

#ifndef ASSIGNMENT_ROTATOR_H
#define ASSIGNMENT_ROTATOR_H
#include <iostream>
#include <vector>
#include "ppm.h"
#include "pgm.h"
#include "PixelFiles/ColorPixel.h"

class Rotator{

public:
    static Rotator *Instance();

    string getInputFile() {return inputFile_;}

    void setInputFile( string &inputFile) { inputFile_ = inputFile; }

    string getOutputFile()  {return outputFile_;}

    void setOutputFile( string &outputFile) { outputFile_ = outputFile; }

    string getRotateDirection() { return rotateDirection_; }

    void setRotateDirection(string &rotateDirection) { rotateDirection_ = rotateDirection; }

    int getAngleOfRotation()  { return angleOfRotation_; }

    void setAngleOfRotation(int angleOfRotation) { angleOfRotation_= angleOfRotation; }

    vector<vector<ColorPixel> > rotatePPM(vector<vector<ColorPixel> > imageContainer,Ppm inPpm);
    vector<vector<GrayPixel> >  rotatePGM(vector<vector<GrayPixel> > , Pgm inPgm);

private:
    Rotator(){};
    ~Rotator();

    static Rotator* instance_;

    string inputFile_ , outputFile_ , rotateDirection_ ;
    int angleOfRotation_;

};



#endif //ASSIGNMENT_ROTATOR_H
