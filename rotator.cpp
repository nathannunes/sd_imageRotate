//
// Created by Nathan Nunes on 10/1/22.
//
#include <iostream>
#include "ppm.h"
#include "pgm.h"

using namespace std;

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

    void rotate(){
        if(inputFile_.substr(inputFile_.size() - 3) == "ppg" ){
            cout << "pgm file found"<<endl;
            //TODO

        }else{
            cout << "ppm file found"<<endl;

            // TODO

            inPpm.readFile(inputFile_);
        }

    }



private:
    Rotator(){};
    ~Rotator();

    static Rotator* instance_;
    string inputFile_ , outputFile_ , rotateDirection_ ;
    int angleOfRotation_;

    // create objects of file types
    Ppm inPpm;
    Ppg inPpg;


};


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
    Rotator* p1 = Rotator::Instance();

    string inputFile = argv[1];
    string outputFile = argv[2];
    string rotateDirection = argv[3];
    int angleOfRotation = atoi(argv[4]);
    //isRotateRight = rotateDirection.ends_with('r');

    p1->setInputFile(inputFile), p1->setOutputFile(outputFile),
    p1->setAngleOfRotation(angleOfRotation),p1->setRotateDirection(rotateDirection);

    p1->rotate();


    return 0;
}
