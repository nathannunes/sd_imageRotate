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

const static string LEFT_ROTATE = "-l";
const static string RIGHT_ROTATE = "-r";


vector<vector<GrayPixel> > Rotator::rotatePGM(vector<vector<GrayPixel> > imageContainer,Pgm inPgm){
    Rotator *p1 = Rotator::Instance();
    long long n = imageContainer.size();
    long long maxH = inPgm.getMaxHeight();
    long long maxW = inPgm.getMaxWidth();
    int iterations = p1->getAngleOfRotation() <= 270 ? p1->getAngleOfRotation()/90 : 0;
    cout << iterations<<endl;

    if(p1->getRotateDirection() == RIGHT_ROTATE){
        //right
        while(iterations > 0){
            for(long long i=0; i<maxH ; i++){
                for(long long j=i ; j<maxW; j++){
                    swap(imageContainer[i][j] , imageContainer[j][i]);
                }
            }
            // swap both ends
            for(int i=0; i<n;i++){
                reverse( imageContainer[i].begin(),imageContainer[i].end());
            }
            //swap Dimensions
            inPgm.swapDimensions();

            iterations--;
        }

    }else if(p1->getRotateDirection() == LEFT_ROTATE){
        //left
        while(iterations > 0){
            for (int i = 0; i < maxH / 2; i++) {
                int top = i;
                int bottom = maxW - 1 - i;
                for (int j = top; j < bottom; j++) {
                    GrayPixel temp = imageContainer[top][j];
                    imageContainer[top][j] = imageContainer[j][bottom];
                    imageContainer[j][bottom] = imageContainer[bottom][bottom - (j - top)];
                    imageContainer[bottom][bottom - (j - top)] = imageContainer[bottom - (j - top)][top];
                    imageContainer[bottom - (j - top)][top] = temp;
                }
            }
            //swap Dimensions
            inPgm.swapDimensions();
            iterations--;
        }
    }

    return imageContainer;

}

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
    p1->setAngleOfRotation(angleOfRotation);


    if (inputFile.substr(inputFile.size() - 3) == PGM) {
        cout << "pgm file found" << endl;
        cout << inputFile;
        vector<vector<GrayPixel> > imageContainer = inPgm.readFile(p1->getInputFile());
        vector<vector<GrayPixel> > rotatedimageContainer = p1->rotatePGM(imageContainer,inPgm);
        inPgm.writeFile(rotatedimageContainer);
    } else if (inputFile.substr(inputFile.size() - 3) == PPM) {
        cout << "ppm file found" << endl;
        vector<vector<ColorPixel> > imageContainer = inPpm.readFile(p1->getInputFile());
        vector<vector<ColorPixel> > rotatedimageContainer = p1->rotatePPM(imageContainer,inPpm);
        inPpm.writeFile(rotatedimageContainer);
    } else { cout << "invalid input " << endl; }

    return 0;
}



