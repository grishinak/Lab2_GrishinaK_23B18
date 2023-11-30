#pragma once
#include <cassert>
#include <vector>
#include <iostream>
#include "weapon.h"

void TestInventory() {

    Inventory inventory;
    Weapon sword("Sword", 20);
    Weapon axe("Axe", 30);

    inventory.AddWeapon(sword);
    inventory.AddWeapon(axe);

    assert(inventory.GetWeapons().size() == 2);
    assert(inventory.GetWeapons()[0].GetDamage() == 20);
    assert(inventory.GetWeapons()[1].GetDamage() == 30);

    cout << "inventory test passed" << endl;
}
