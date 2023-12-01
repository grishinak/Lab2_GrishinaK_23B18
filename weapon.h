#pragma once
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Weapon {
public:
    Weapon(string name, int damage) : name(name), damage(damage) {}

    int GetDamage() const {
        return damage;
    }

private:
    string name;
    int damage;
};
void TestWeapon() {
    Weapon sword("Sword", 20);

    assert(sword.GetDamage() == 20);

    cout << "Weapon test passed." << endl;
}
