#pragma once
#include <iostream>
#include <string>

//#include "character.h"
using namespace std;

class NPC : public Character {
public:
    NPC(string name, int health, int damage, string role) : Character(name, health, damage), role(role) {}

    string GetRole() const {
        return role;
    }

private:
    string role;
};
void TestNPC() {
    NPC merchant("Merchant", 100, 10, "Trader");
    assert(merchant.GetName() == "Merchant");
    assert(merchant.GetRole() == "Trader");

    cout << " NPC test passed." << endl;
};
