#pragma once
#include "pet.h"

class Dog : public Pet {
public:

    void bark() {
        cout << "dog bark function" << endl;
    }
    string GetBreed()
    {
        return breed;
    }

    void SetBreed(string valueBreed)
    {
        breed = valueBreed;
    }
private:
    string breed;//+ get + set
};
