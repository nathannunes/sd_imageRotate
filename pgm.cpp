//
// Created by Nathan Nunes on 9/26/22.
//

#include "pgm.h"
#include <iostream>
#include "PixelFiles/grayPixel.h"
#include "Rotator.h"

void swapVectorRows(int i, int i1, vector<GrayPixel> vector1);

using namespace std;

const static string LEFT_ROTATE = "-l";
const static string RIGHT_ROTATE = "-r";

Pgm::Pgm(){
    //ctor
}

Pgm::~Pgm(){
    //dtor
}

int Pgm::readFile(string filePath, string outputFilePath){
    ifstream inputFile(filePath,ifstream::binary);
    inputFile>>magicNum;
    inputFile.seekg(1,inputFile.cur);
    char c;
    inputFile.get(c);
    if(c=='#'){
        while(c!='\n')
            inputFile.get(c);
    }
    inputFile >> maxWidth;
    inputFile >> maxHeight;
    inputFile >> maxPixelSize;


    if(magicNum == "P2"){
        while(!inputFile.eof()){
            int gray;
            inputFile>>gray;
            GrayPixel pixel(gray);
            grayPixelsVector.push_back(pixel);
        }
        cout<<grayPixelsVector.size()<<endl;
    }
     for(int i=0;i<maxHeight;i++){
         vector<GrayPixel> columns;
         for(int j=0;j<maxWidth;j++){
             columns.push_back(grayPixelsVector.front());
             grayPixelsVector.erase(grayPixelsVector.begin());
         }
         //cout<<"got column "<<columns.size()<<endl;
         imageContainer.push_back(columns);
         //cout<<"got row "<<imageContainer.size()<<endl;
     }
     cout<<"size is "<<imageContainer.size()<<endl;
     cout<<"size 2 is "<<imageContainer[0].size()<<endl;

    Rotator *p1 = Rotator::Instance();

    int n = imageContainer.size();
    if(p1->getRotateDirection() == RIGHT_ROTATE){
        //right

        for(int i=0; i<n ; i++){
            for(int j=i ; j<n; j++){
                swap(imageContainer[i][j] , imageContainer[j][i]);
            }
        }
        for(int i=0; i<n;i++){
            reverse( imageContainer[i].begin(),imageContainer[i].end());
        }
    }else if(p1->getRotateDirection() == LEFT_ROTATE){
        //left
        for (int i = 0; i < n / 2; i++) {
            int top = i;
            int bottom = n - 1 - i;
            for (int j = top; j < bottom; j++) {
                GrayPixel temp = imageContainer[top][j];
                imageContainer[top][j] = imageContainer[j][bottom];
                imageContainer[j][bottom] = imageContainer[bottom][bottom - (j - top)];
                imageContainer[bottom][bottom - (j - top)] = imageContainer[bottom - (j - top)][top];
                imageContainer[bottom - (j - top)][top] = temp;
            }
        }
    }

    ofstream outData;
    outData.open(outputFilePath);
    if(!outData.is_open()){
        cout<<"file not opened";
        return 1;
    }

    outData<<magicNum<<"\n";
    outData<<maxHeight<< " "<<maxWidth<<"\n";
    for(int i=0;i<maxHeight;i++){
        for(int j=0;j<maxWidth;j++){
            outData<<imageContainer[i][j].getGrayValue()<<"\n";
        }
    }
    cout<<"done,closing file ";
    outData.close();

}



