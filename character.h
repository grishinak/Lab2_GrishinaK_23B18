#pragma once
#include <string>

class Character {
public:
    Character(string name, int health, int damage) : name(name), health(health), damage(damage) {}

    string GetName() const {
        return name;
    }

    int GetHealth() const {
        return health;
    }

    int GetDamage() const {
        return damage;
    }

    void TakeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }

    bool IsAlive() const {
        return health > 0;
    }

private:
    string name;
    int health;
    int damage;
};
