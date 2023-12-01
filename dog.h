#pragma once
#include "pet.h"

class Dog : public Pet {
public:

    void bark() {
        cout << "dog bark function" << endl;
    }
private:
    string breed;
};
