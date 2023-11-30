#pragma once
#include <cassert>
#include <vector>
#include <iostream>
#include "monster.h"

void TestMonster() {
    Monster goblin("Goblin", 30, 5);
    assert(goblin.GetName() == "Goblin");
    assert(goblin.GetHealth() == 30);
    assert(goblin.GetDamage() == 5);

    cout << "Monster test passed" << endl;
}
