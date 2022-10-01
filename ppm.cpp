#include "ppm.h"
#include "PixelFiles/ColorPixel.h"


Ppm::Ppm(){
    //ctor
}

Ppm::~Ppm(){
    //dtor
}

int Ppm::readFile(string filePath){
    ifstream inputFile(filePath,ifstream::binary);
    if(!inputFile.is_open()){
       cout<<"Cannot read file";
       return 1;
    }
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
              int red,green,blue;
              inputFile>>red>>green>>blue;
              ColorPixel pixel(red,green,blue);
              colorPixelsVector.push_back(pixel);
              //if() break;
        }

        //int testVal =
        cout<<colorPixelsVector.size()<<endl;
    }
    for(int i=0;i<maxHeight;i++){
        vector<ColorPixel> columns;
        for(int j=0;j<maxWidth;j++){
            columns.push_back(colorPixelsVector.front());
            //cout<<"got in"<<colorPixelsVector.front().getRedValue()<<endl;
            //imageContainer[i][j] = colorPixelsVector.front();
            colorPixelsVector.erase(colorPixelsVector.begin());
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
            outData<<imageContainer[i][j].getRedValue()<<"\n"<<imageContainer[i][j].getGreenValue()
            <<"\n"<<imageContainer[i][j].getBlueValue()<<"\n";
        }
    }
    cout<<"done,closing file ";
    outData.close();
}
