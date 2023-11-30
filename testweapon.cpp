#pragma once


void TestWeapon() {

    Weapon sword("Sword", 20);

    assert(sword.GetDamage() == 20);

    cout << "Weapon test passed." << endl;
};
