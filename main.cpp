#include <iostream>
#include <ctime>
using namespace std;
#include <cassert>
#include <vector>
#include <string>

#include "player.h"//game player
#include "enemy.h"//game enemy

//later classes only with test, to fit the ctiteria
#include "weapon.h"
#include "inventory.h"

#include "character.h"
#include "monster.h"//inherited from character class
#include "boss.h"//inherited from character class
#include "npc.h"//inherited from character class

#include "animal.h"// +4 classes inherited in line from animal: animal-pet-dog-pupppy and tests for them




void gameStory() {

    cout << endl << endl;
    cout << "_________________________________________________________________________________________________________________________" << endl;
    cout << "|                                           WELCOME TO THE LAB#2 GAME!                                                  |" << endl;
    cout << "|                                           (Grishina Kseniya 23-b18)                                                   |" << endl;
    cout << "|                                                                                                                       |" << endl;
    cout << "|  You are standing in a dark forest. In front of you is a someone that doesnt look friendly. and i think it is hungry. |" << endl;
    cout << "|                                                                                                                       |" << endl;
    cout << "|  You know you must defeat it to survive. But the enemy seems to be strong, and you do not have much health.           |" << endl;
    cout << "|                                                                                                                       |" << endl;
    cout << "|  You must damage it to weaken it, but you must also remember to heal yourself so you do not die yourself.             |" << endl;
    cout << "|                                                                                                                       |" << endl;
    cout << "|                                                                                                                       |" << endl;
    cout << "|_______________________________________________________________________________________________________________________|" << endl << endl << endl;

    cout << "______________________________________________________________________________" << endl;
    cout << "|                                 CONTROL INFO                               |" << endl;
    cout << "|                                                                            |" << endl;
    cout << "|  On each turn, you can do one of two actions:                              |" << endl;
    cout << "|                                                                            |" << endl;
    cout << "|  - Damage the enemy.                                                       |" << endl;
    cout << "|  - Heal yourself.                                                          |" << endl;
    cout << "|                                                                            |" << endl;
    cout << "| If you damage the ogre enough, it will die. If you die, the game will end. |" << endl;
    cout << "|____________________________________________________________________________|" << endl << endl;
}

void battleLoop(Player player, Enemy enemy)
{

    char playerChoice;

    do {
        cout << "press A to attack or H to heal" << endl;
        cin >> playerChoice;
        if (playerChoice == 'A' || playerChoice == 'a')
        {

            //attack
            enemy.TakeDamage(player.GiveDamage());

            if (enemy.GetHealth() > 0)//if enemy alive he attacks
            {
                cout << "ha ha ha, its my turn now!!!" << endl;
                player.TakeDamage(enemy.GiveDamage());
            }


        }
        else if (playerChoice == 'H' || playerChoice == 'h')
        {

            //healing
            player.Heal();

            if (enemy.GetHealth() > 0)//if enemy alive he attacks
            {
                cout << "ha ha ha, its my turn now!!!" << endl;
                player.TakeDamage(enemy.GiveDamage());
            }

        }
        else
        {
            cout << "invalid input" << endl;
        }
         cout << "\n\n" << endl;
    } while (player.GetHealth() > 0 && enemy.GetHealth() > 0);
}

int main() {
    /*  tests */
    TestWeapon();
    TestInventory();

    //puppy is the animal last inherited class test(means that all animals classes work (incapsulation priciple))
    Puppy puppy;

    puppy.makeSound(); // animal's method
    puppy.play(); // pet's method
    puppy.bark(); // dpg's method
    puppy.wagTail(); // puppy's method



    // obj inherited from character class tests:
    TestMonster();
    TestBoss();
    TestNPC();

    /* working cli game code    */

    gameStory();

    char userInput;

    do
    {
        cout << "press S to Start the game and any other key to exit!" << endl;
        cin >> userInput;

        if (userInput == 'S' || userInput == 's')
        {
            Player playerObj;//creating a player's obj
            Enemy enemyObj;//creating a enemy's obj
            battleLoop(playerObj, enemyObj);// battle mechanics including:  attack and heal mechanics // (enemy and player interaction)

        }
        else
        {
            cout << "Thanks for playing!" << endl;
        }


    } while (userInput == 'S' || userInput == 's');

    return 0;
}
