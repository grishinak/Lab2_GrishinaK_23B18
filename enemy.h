#pragma once

using namespace std;

class Enemy
{
public:

    Enemy()
    {
        cout << "i'm an enemy" << endl;
    }


    int GetHealth()
    {
        return health;
    }
    void TakeDamage(int damage)
    {

        cout << " a critical hit to enemy) " << endl;
        cout << "player is dealing damage of " << damage << "to the enemy" << endl;
        health = health - damage;



        if (health < 0)
        {
            cout << "enemy died. You win!!! :) ) " << endl;
        }
        else
        {
            cout << "enemy's current health after recieving the damage is: " << health << endl;
        }


    }

    int GiveDamage()
    {
        srand(time(0));
        int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);

        return randomDamage;
    }


private:
    int health = 100;

    int maxDamage = 20;
    int minDamage = 10;



};