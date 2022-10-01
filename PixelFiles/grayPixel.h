//
// Created by Nathan Nunes on 9/27/22.
//

#ifndef ASSIGNMENT_GRAYPIXEL_H
#define ASSIGNMENT_GRAYPIXEL_H

class GrayPixel{
private:
    int grayValue;
    GrayPixel(){grayValue=0;};
public:
    GrayPixel(int grayValue){
        this->grayValue=grayValue;
    }

    ~GrayPixel();
};

#endif //ASSIGNMENT_GRAYPIXEL_H
