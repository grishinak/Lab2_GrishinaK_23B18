#pragma once
#include <iostream>
#include <string>


using namespace std;

class Animal {
public:
 
    int GetAge() 
    {
        return age;
    }

    void SetAge(int valueAge);

    string GetName()
    {
        return name;
    }

    void SetName(string valueName)
    {
        name = valueName;
    }

    void makeSound() {
        cout << "animal makesound function" << endl;
    }
    
private:
    int age;
    string name;
};
