#pragma once
#include <iostream>
#include <cassert>
#include "character.h"

class Monster : public Character {
public:
    Monster(string name, int health, int damage) : Character(name, health, damage) {}
};
