#include <iostream>
#include <cstdlib>
#include <time.h>

#include "fighters.h"

using namespace std;


Fighter::Fighter(const string& FighterName) {

    // "random" number between 25 and 50
    // min + (rand() % (max - min + 1))


    this->name = FighterName;
    this->healthPoints = 100;
    this->offensePoints = 25 + (rand() % (50 - 25 + 1));
    this->defensePoints = 25 + (rand() % (50 - 25 + 1));

}


void Fighter::attack(Fighter& enemy) { //ampersand stands for a reference
    //"its kind of like a pointer, but not really"

    int hitpoints = 0;

    if (this->dead != true) {
        if (this->specialAttack() != 0) {

            hitpoints = this->specialAttack();

            if (enemy.specialDefense() == 100) {
                cout << "dodged" << endl;

            }
            else {
                enemy.healthPoints -= hitpoints;
                cout << "special attack damage: " << hitpoints << endl;
            }


        }
        else {

            hitpoints = this->offensePoints;
            hitpoints = rand() % (hitpoints + 1);
            enemy.healthPoints -= hitpoints;

        }




        cout << this->name << " atack  " << hitpoints << " damage" << endl;
        cout << enemy.name << " had " << enemy.healthPoints << " Healthpoints" << "\n" << endl;


        if (enemy.healthPoints <= 0) {    //death

            enemy.dead = true;

            cout << enemy.name << " was killed by" << this->name << endl;

        }
        else {  //defense

            int defensepoints = enemy.defensePoints;
            defensepoints = rand() % (defensepoints + 1);

            this->healthPoints -= defensepoints;

            cout << "random def points" << defensepoints << endl;

            if (this->healthPoints <= 0) {    //defend

                this->dead = true;

                cout << this->name << " was defended by" << enemy.name << endl;

            }


        }

                cout << "def" << this->defensePoints << endl;
                cout << "off" << this->offensePoints << endl;
                cout << "hp" << this->healthPoints << endl;
        
        
        
                cout << "def" << enemy.defensePoints << endl;
                cout << "off" << enemy.offensePoints << endl;
                cout << "hp" << enemy.healthPoints << endl;
    }
}

const void Fighter::showStats() {

    if (healthPoints == 100) {
        cout << "full hp" << endl;
    }
}

Warrior::Warrior(const string& FighterName) : Fighter(FighterName) {

    description = "The warrior is a brave fighter that sometimes can attack very strongly (one by six chance of double hitpoints).";

}

Ninja::Ninja(const string& FighterName) : Fighter(FighterName) {

    description = "Ninjas move very fast, hence they can escape attacks sometimes but still launch a counterattack (one by six chance that an attack does not cause any damage).";

}

ChuckNorris::ChuckNorris(const string& FighterName) : Fighter(FighterName) {

    description = "The warrior is a brave fighter that sometimes can attack very strongly (one by six chance of double hitpoints).";

}

Mage::Mage(const string& FighterName) : Fighter(FighterName) {

    description = "The warrior is a brave fighter that sometimes can attack very strongly (one by six chance of double hitpoints).";

}

// special attack/defense
double Warrior::specialAttack() {
    int double_hitpoints = 25 + (rand() % (50 - 25 + 1));
    int chance = 6;

    //'random' number range 0-6
    chance = rand() % (6 - 0 + 1);
    if (chance == 0) {
        double_hitpoints = double_hitpoints * 2;

    }

    return double_hitpoints;    // warrior deals double damage
}

double Warrior::specialDefense() {

    return 0;   //no special defense
}

double Ninja::specialAttack() {

    return 0;   //no special attack
}

double Ninja::specialDefense() {

    int chance = 6;

    //'random' number range 0-6
    chance = rand() % (6 - 0 + 1);
    if (chance == 0) {
        return 100;   //0 dmg -> dodge
    }
    else {
        return 0;   //when dodge fails
    }
}

double ChuckNorris::specialAttack() {

    int chance = 6;

    //'random' number range 0-6
    chance = rand() % (6 - 0 + 1);
    if (chance == 0) {
        return 100; //roundhouse kick

    }
    else {
        return 0;   //when roundhouse kick fails
    }
}

double ChuckNorris::specialDefense() {
    return 0;
}

double Mage::specialAttack() {
    //mage drinks potion and deals more dmg
    int dmg = 25 + (rand() % (55 - 25 + 1));

    return dmg;
}

double Mage::specialDefense() {
    return 0;
}

void create(Fighter* fighter[]) {

    int fighterNum = 0;

    cout << "How many fighters do you want to create? (1-10)" << endl;
    cin >> fighterNum;

    if (fighterNum < 1) { fighterNum = 1; }
    if (fighterNum > 10) { fighterNum = 10; }

    for (int i = 0; i < fighterNum; i++) {

        int fighterType = 0;
        string name = "";
        string klasse = "";

        cout << "\nFighter number: " << i + 1 << endl;
        cout << "Please enter name: " << endl;
        cin >> name;

        while (1) {

            cout << "\nSelect class:  \n  -1.Warrior\n  -2.Ninja\n  -3.ChuckNorris\n  -4.Mage\n " << endl;

            cin >> fighterType;


            switch (fighterType) {
            case 1:
            {
                fighter[i] = new Warrior(name);

                break;
            }
            case 2:
            {
                fighter[i] = new Ninja(name);

                break;
            }
            case 3:
            {
                fighter[i] = new ChuckNorris(name);

                break;
            }
            case 4:
            {
                fighter[i] = new Mage(name);

                break;
            }
            default:
            {
                cout << "Not a valid entry!" << endl;

                break;
            }
            }
            break; //coming out of while loop
        }
    }
    cout << "All fighters have been successfully created and are now ready." << endl;
}

void fight(Fighter* fighterarray[], int fighter1, int fighter2) {


    while (fighterarray[fighter1]->dead != true && fighterarray[fighter2]->dead != true) {

        fighterarray[fighter1]->attack(*fighterarray[fighter2]);
        fighterarray[fighter2]->attack(*fighterarray[fighter1]);
    }

    if (fighterarray[fighter1]->dead == true) {
        cout << fighterarray[fighter1]->name << " has lost" << endl;
        delete fighterarray[fighter1];
        fighterarray[fighter1] = nullptr;
    }
    else if (fighterarray[fighter2]->dead == true) {
        cout << fighterarray[fighter2]->name << " has lost" << endl;
        delete fighterarray[fighter2];
        fighterarray[fighter2] = nullptr;
    }


}

void pick(Fighter* arrayname[]) {

    view(arrayname);
    int fighter1, fighter2;

    cout << "Choose fighter 1:" << endl;
    cin >> fighter1;
    cout << "Choose fighter 2:" << endl;
    cin >> fighter2;

    fight(arrayname, fighter1 - 1, fighter2 - 1);

}

void lastManStanding(Fighter* fighterarray[]) {

    int j = 9;
    int i = 0;
    int survivor = 0;
    int round = 0;

    while (1) {

        round++;
                cout << "round: "<< round << endl;
        //
                cout << i << " vs " << j <<  endl;

        if (fighterarray[i] != nullptr && fighterarray[j] != nullptr) {
            fight(fighterarray, j, i);
        }
        if (fighterarray[i] != nullptr) {
            j--;
            if (j <= 0) {
                j = 9;
            }

        }
        if (fighterarray[j] != nullptr) {
            i++;
            i = i % 10;
            if (i == j) {
                i++;
                i = i % 10;
            }
        }


        for (int x = 0; x < 10; x++) {
            if (fighterarray[x] != nullptr) {
                survivor++;
                cout << x << " alive" << endl;
            }
        }
        if (survivor == 1) {
            cout << "only 1 survivor left" <<endl;
            break;
        }
        survivor = 0;
    }

    cout << "survivors " << survivor << endl;
}


// lists all fighters
void view(Fighter* arrayname[]) {

    cout << "List:" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "   " << i + 1 << ".) ";
        if (arrayname[i] != 0) {
            cout << arrayname[i]->name << endl;
            arrayname[i]->showStats();

        }
        else {
            cout << "-empty-" << endl;
        }
    }
}