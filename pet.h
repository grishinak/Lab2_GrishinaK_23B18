#pragma once
#include "animal.h"

class Pet : public Animal {
public:

    void play() {
        cout << "pet play function" << endl;
    }

    bool GetHasOwner();

    void SetHasOwner(bool valueHasOwner);

private:
    bool hasOwner;
};
