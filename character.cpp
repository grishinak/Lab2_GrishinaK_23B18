#pragma once
#include <string>
#include "character.h"

void TakeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}