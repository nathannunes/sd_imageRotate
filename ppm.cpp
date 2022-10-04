#include "ppm.h"
#include <string>
#include "ColorPixel.h"
#include "Rotator.h"

Ppm::Ppm(){
    //ctor
}

Ppm::~Ppm(){
    //dtor
}

vector<vector<ColorPixel> > Ppm::readFile(string filePath){
    
    ifstream inputFile(filePath,ifstream::binary);
    if(!inputFile.is_open()){
        cout<<"Cannot read file";
        return vector<vector<ColorPixel> >();
    }
    
    string magicNumLocal;
    inputFile>>magicNumLocal;
    this->magicNum = magicNumLocal;
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
    
    if(this->magicNum == "P3"){
        while(!inputFile.eof()){
            int red,green,blue;
            inputFile>>red>>green>>blue;
            ColorPixel pixel(red,green,blue);
            colorPixelsVector.push_back(pixel);
        }
        cout<<colorPixelsVector.size()<<endl;
    }
    if(this->magicNum == "P6"){
        vector<unsigned char> buffer(maxHeight*maxWidth*3);
        if(inputFile.read((char*)buffer.data(),maxHeight*maxWidth*3)){
            cout<<"it worked";
            for(int i=0;i<(maxHeight*maxWidth*3)-2;i=i+3){
                ColorPixel pixel(buffer[i],buffer[i+1],buffer[i+2]);
                colorPixelsVector.push_back(pixel);
            }
            
        }
    }
    long int colorPixIdx =0;
    for(int i=0;i<maxHeight;i++){
        vector<ColorPixel> columns;
        for(int j=0;j<maxWidth;j++){
            columns.push_back(colorPixelsVector[colorPixIdx++]);
        }        
        imageContainer.push_back(columns);        
    }
    return imageContainer;


}

void Ppm::writeFile(vector<vector<ColorPixel> > imageContainerT){
	Rotator *p1 = Rotator::Instance();
    ofstream outData;
    outData.open(p1->getOutputFile(),ios::binary);
    if(!outData.is_open()){
        cout<<"file not opened";
        return;
    }
    if(this->magicNum == "P3"){
        outData<<"P3"<<"\n";
    }
    if(this->magicNum == "P6"){
        outData<<"P6"<<"\n";
    }
    outData<<maxWidth<<" "<<maxHeight<<"\n";
    outData<<maxPixelSize<<"\n";
    for(long long unsigned int i=0;i<imageContainerT.size();i++){
        for(long long unsigned int j=0;j<imageContainerT[i].size();j++){
            if(this->magicNum == "P3"){
                outData<<imageContainerT[i][j].getRedValue()<<"\n"<<imageContainerT[i][j].getGreenValue()<<"\n"<<imageContainerT[i][j].getBlueValue()<<"\n";
            }
            if(this->magicNum == "P6"){               
                outData<<imageContainerT[i][j].getBinRed()<<imageContainerT[i][j].getBinGreen()<<imageContainerT[i][j].getBinBlue();
            }

        }
    }
    cout<<"done,closing file ";
    outData.close();
}

int Ppm::getMaxHeight(){
    return this->maxHeight;
}
int Ppm::getMaxWidth(){
    return this->maxWidth;
}

string Ppm::getMagicNum(){
    return this->magicNum;
}
