#pragma once

class Boss : public Monster {
public:
    Boss(string name, int health, int damage, int bossLevel) : Monster(name, health, damage), bossLevel(bossLevel) {}

    int GetBossLevel() const {
        return bossLevel;
    }

private:
    int bossLevel;
};
