#pragma once
#pragma once
#include <cassert>
#include <vector>
#include <iostream>
#include "weapon.h"

using namespace std;


class Inventory {
public:
    void AddWeapon(const Weapon& weapon) {
        weapons.push_back(weapon);
    }

    const vector<Weapon>& GetWeapons() const {
        return weapons;
    }

private:
    vector<Weapon> weapons;
};
void TestInventory() {
    Inventory inventory;
    Weapon sword("Sword", 20);
    Weapon axe("Axe", 30);

    inventory.AddWeapon(sword);
    inventory.AddWeapon(axe);

    assert(inventory.GetWeapons().size() == 2);

    // 
    assert(inventory.GetWeapons()[0].GetDamage() == 20);
    assert(inventory.GetWeapons()[1].GetDamage() == 30);

    cout << "inventory test passed" << endl;
}
