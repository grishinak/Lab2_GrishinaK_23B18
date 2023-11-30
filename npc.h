#pragma once
#include <iostream>
#include <string>

#include "character.h"

class NPC : public Character {
public:
    NPC(string name, int health, int damage, string role) : Character(name, health, damage), role(role) {}

    string GetRole() const {
        return role;
    }

private:
    string role;
};
