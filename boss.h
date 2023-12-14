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
void TestBoss() {
    Boss dragon("Dragon Boss", 150, 30, 5);
    assert(dragon.GetName() == "Dragon Boss");
    assert(dragon.GetHealth() == 150);
    assert(dragon.GetDamage() == 30);
    assert(dragon.GetBossLevel() == 5);

    cout << "Boss test passed." << endl;
}