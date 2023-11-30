#pragma once
#include <string>
#include <cassert>
#include <iostream>


class Weapon {
public:
    Weapon(string name, int damage) : name(name), damage(damage) {}

    string GetName()
    {
        return name;
    }

    void SetName(string valueName);

    int GetDamage() const
    {
        return damage;
    }

    void SetDamage(int valueDamage);

private:
    string name;
    int damage;
};
