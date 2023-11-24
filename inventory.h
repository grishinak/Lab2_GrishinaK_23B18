#pragma once
#include <cassert>
#include <vector>
#include <iostream>
#include "weapon.h"

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
