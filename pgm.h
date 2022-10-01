//
// Created by Nathan Nunes on 9/26/22.
//

#ifndef ASSIGNMENT_PGM_H
#define ASSIGNMENT_PGM_H

#include <string>

using namespace std;

class Pgm {
private:
    static Pgm *instance;  // single Instance
    // private constructor

protected:
    string magicNumber;
    int height;
    int width;
    int max_value=255;

public:
    static Pgm* getInstance();

    Pgm() : height(0),width(0),magicNumber(""),max_value(255) {}
};

#endif //ASSIGNMENT_PGM_H
