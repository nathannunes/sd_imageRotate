//
// Created by Nathan Nunes on 9/26/22.
//

#include "pgm.h"
#include <iostream>
#include "PixelFiles/grayPixel.h"
using namespace std;


Pgm::Pgm(){
    //ctor
}

Pgm::~Pgm(){
    //dtor
}


int Pgm::readFile(string filePath){
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


    if(magicNum == "P3"){
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
         cout<<"got column "<<columns.size()<<endl;
         imageContainer.push_back(columns);
         cout<<"got row "<<imageContainer.size()<<endl;
     }
     cout<<"size is "<<imageContainer.size()<<endl;
     cout<<"size 2 is "<<imageContainer[0].size()<<endl;

     //Transposing matrix
     for(int i=0;i<maxHeight;i++){
         for(int j=i+1;j<maxWidth;j++){
             swap(imageContainer[i][j],imageContainer[j][i]);
         }
     }
    ofstream outData;
    outData.open("createImgOutput.txt");
    if(!outData.is_open()){
        cout<<"file not opened";
        return 1;
    }

    for(int i=0;i<maxHeight;i++){
        for(int j=0;j<maxWidth;j++){
            outData<<imageContainer[i][j].getGrayValue()<<"\n";
        }
    }
    cout<<"done,closing file ";
    outData.close();

}


