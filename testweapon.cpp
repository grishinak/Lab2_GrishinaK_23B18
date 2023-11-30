#pragma once
#include <cassert>
#include <iostream>
#include "weapon.h"

void TestWeapon() {

    Weapon sword("Sword", 20);

    assert(sword.GetDamage() == 20);

    cout << "Weapon test passed." << endl;
};
