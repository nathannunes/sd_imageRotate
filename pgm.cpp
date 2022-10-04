//
// Created by Nathan Nunes on 9/26/22.
//

#include "pgm.h"
#include <iostream>
#include "grayPixel.h"
#include "Rotator.h"


using namespace std;

Pgm::Pgm(){
    //ctor
}

Pgm::~Pgm(){
    //dtor
}

int Pgm::getMaxWidth() {
    return this->maxWidth;
}
int Pgm::getMaxHeight() {
    return this->maxHeight;
}

vector<vector<GrayPixel> > Pgm::readFile(string filePath){
    Rotator *p1 = Rotator::Instance();
    cout << endl;
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
    if(magicNum == "P5"){
        inputFile >> maxPixelSize;
    }


   // cout <<magicNum<< " "<<  maxWidth << " " << maxHeight << endl;

   // cout << p1->getRotateDirection() << endl;
    // Read files based on Magic Number
    if(magicNum == "P2"){
        while(!inputFile.eof()){
            int gray;
            inputFile>>gray;
            GrayPixel pixel(gray);
            grayPixelsVector.push_back(pixel);
        }
        cout<<grayPixelsVector.size()<<endl;
    } else if(magicNum == "P5"){
        vector<unsigned char> buffer(maxHeight*maxWidth);
        if(inputFile.read((char*)buffer.data(),maxHeight*maxWidth)){
            //cout<<"it worked"<<endl;
            for(long long i=0;i<(maxHeight*maxWidth);i=i+1){
                GrayPixel pixel(buffer[i]);
                grayPixelsVector.push_back(pixel);
            }
            //cout<<"size is "<<grayPixelsVector.size()<<endl;
        }
    }

    // Put pixel values in 2D VECTOR
     long int colorPixIdx =0;
     for(long long i=0;i<maxHeight;i++){
         vector<GrayPixel> columns;
         for(long long j=0;j<maxWidth;j++){
             columns.push_back(grayPixelsVector[colorPixIdx++]);
         }
         imageContainer.push_back(columns);
      //   cout << "pushed column : " << i <<endl;
     }
     //cout<<"size is "<<imageContainer.size()<<endl;
     //cout<<"size 2 is "<<imageContainer[0].size()<<endl;

    return imageContainer;

}


void Pgm::writeFile(vector<vector<GrayPixel> > rotImageContainer){
    Rotator *p1 = Rotator::Instance();

    ofstream outData;
    outData.open(p1->getOutputFile());
    if(!outData.is_open()){
        cout<<"file not opened"<<endl;
        return;
    }
    outData<<magicNum<<"\n";
    outData<< "#"<<"\n";
    outData<<maxWidth<<"  "<<maxHeight<<"\n";
    if(magicNum == "P5"){
        outData << maxPixelSize<<"\n";
    }

    if(magicNum == "P2"){
        for(int i=0;i<maxHeight;i++){
            for(int j=0;j<maxWidth;j++){
                outData<<rotImageContainer[i][j].getGrayValue()<<"\n";
            }
        }
        cout<<"done,closing file "<<endl;
    }else if (magicNum == "P5"){
        for(long long unsigned int i=0;i<rotImageContainer.size();i++){
            for(long long unsigned int j=0;j<rotImageContainer[i].size();j++){
                outData<<rotImageContainer[i][j].getBinGrayValue();
            }
        }
        cout<<"done,closing file "<<endl;
    }

    outData.close();
}
