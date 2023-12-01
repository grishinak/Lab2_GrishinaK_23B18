#pragma once

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:

    void makeSound() {
        cout << "animal makesound function" << endl;
    }
private:
    int age;
    string name;
};

