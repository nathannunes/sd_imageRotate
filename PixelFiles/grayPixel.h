//
// Created by Nathan Nunes on 9/27/22.
//

#ifndef ASSIGNMENT_GRAYPIXEL_H
#define ASSIGNMENT_GRAYPIXEL_H

class GrayPixel{
private:
    int grayValue;
    unsigned char binGrayValue;
    GrayPixel(){grayValue=0;};
public:
    GrayPixel(int grayValue){
        this->grayValue=grayValue;
    }
    GrayPixel(unsigned char binGrayValue){
        this->binGrayValue=binGrayValue;
    }

    int getGrayValue(){
        return this->grayValue;
    }
    unsigned char getBinGrayValue(){
        return this->binGrayValue;
    }

    ~GrayPixel(){};
};
#endif //ASSIGNMENT_GRAYPIXEL_H
