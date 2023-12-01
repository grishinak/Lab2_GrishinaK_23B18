#pragma once

using namespace std;

class Player
{
public:

    Player()
    {
        cout << "(player obj is created, his introduction text)" << endl;
        cout << "hi! i am a knight. we need to save this kingdom from the enemy!" << endl;
        cout << "________________________" << endl;
        cout << "player's Attack range is between " << minDamage << " - " << maxDamage << endl;
        cout << "________________________" << endl;
        cout << "player's Healing Range is between " << minHealing << " - " << maxHealing << endl;
        cout << "________________________" << endl;
    }//constructing object with introdction in terminal

    int GetHealth()
    {
        return health;
    }//getter

    void TakeDamage(int damage)
    {
        cout << "Ohh no, a critical hit to player:() " << endl;
        cout << "Enemy is dealing damage of " << damage << "to the player" << endl;
        health = health - damage;

        if (health < 0)
        {
            cout << "player died... game over" << endl;
        }


        else
        {
            cout << "player's current health after recieving the damage is: " << health << endl;
        }

    }

    int GiveDamage() //atacking mechanics
    {
        srand(time(0));
        int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);

        cout << "player is performing hit of " << randomDamage << " to the enemy" << endl;

        return randomDamage;
    }

    void Heal()// healing machanic
    {
        srand(time(0));
        int randomHeal = (rand() % (maxHealing - minHealing + 1) + minHealing);

        health = health + randomHeal;

        cout << "player Healed with HP of " << randomHeal << endl;

        cout << "Player's health afyer healing is " << health << endl;
    }

private:
    int health = 100;

    int maxDamage = 30;
    int minDamage = 20;

    int maxHealing = 15;
    int minHealing = 8;

};
