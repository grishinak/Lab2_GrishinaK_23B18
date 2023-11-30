#pragma once
#include <string>
#include <cassert>
#include <iostream>
#include "boss.h"

void TestBoss() {
    Boss dragon("Dragon Boss", 150, 30, 5);
    assert(dragon.GetName() == "Dragon Boss");
    assert(dragon.GetHealth() == 150);
    assert(dragon.GetDamage() == 30);
    assert(dragon.GetBossLevel() == 5);

    cout << "Boss test passed." << endl;
}
