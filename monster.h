#pragma once
#include <iostream>
#include <cassert>
#include "character.h"


class Monster : public Character {
public:
    Monster(string name, int health, int damage) : Character(name, health, damage) {}
};
void TestMonster() {
    Monster goblin("Goblin", 30, 5);
    assert(goblin.GetName() == "Goblin");
    assert(goblin.GetHealth() == 30);
    assert(goblin.GetDamage() == 5);

    cout << "Monster test passed" << endl;
}
