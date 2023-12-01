#pragma once
#include "animal.h"

class Pet : public Animal {
public:


    void play() {
        cout << "pet play function" << endl;
    }
private:
    bool hasOwner;
};
