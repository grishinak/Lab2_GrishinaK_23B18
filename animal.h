#pragma once


#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    Animal()//constructor po umolchaniyu
    {

    }
    ~Animal()//destructor po umolchaniyu
    {
    }

    void makeSound() {
        cout << "animal makesound function" << endl;
    }
private:
    int age;
    string name;
};

class Pet : public Animal {
public:


    void play() {
        cout << "pet play function" << endl;
    }
private:
    bool hasOwner;
};

class Dog : public Pet {
public:

    void bark() {
        cout << "dog bark function" << endl;
    }
private:
    string breed;
};

class Puppy : public Dog {
public:


    void wagTail() {
        cout << "puppy wigtail function" << endl;
    }
};