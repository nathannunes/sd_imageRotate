//
// Created by Nathan Nunes on 9/26/22.
//

#include "pgm.h"
#include <iostream>

using namespace std;

Pgm *Pgm::instance = 0;

Pgm* Pgm::getInstance() {
    if (instance == nullptr) {
        instance = new Pgm();
    }
    return(instance);
}