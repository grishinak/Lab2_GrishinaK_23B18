#ifndef TESTS
#include <iostream>
#include <string>

#include "fighters.h"

#include <cstdlib>

using namespace std;


int main() {


    Fighter* fighter[10] = { 0 };


    while (1) {

        int iMenuSelect = 0;


        // menu design with selection

        cout << "\nMenu: " << endl;
        cout << " _________________________" << endl;
        cout << "/ \\         FIGHT        \\" << endl;
        cout << "\\_|                       |" << endl;
        cout << "  |  1. CREATE FIGHTER    |" << endl;
        cout << "  |  2. PICK 2 FIGHTERS   |" << endl;
        cout << "  |  3. LAST MAN STANDING |" << endl;
        cout << "  |  4. VIEW FIGHTERS     |" << endl;
        cout << "  |  5. DELETE FIGHTER    |" << endl;
        cout << "  |  6. MANUAL/INFO       |" << endl;
        cout << "  |  7. QUIT              |" << endl;
        cout << "  |                       |" << endl;
        cout << "  |  _____________________|_" << endl;
        cout << "  \\_/______________________/" << endl;
        cout << "\nPlease use the menu items (numbers) to navigate: ";

        cin >> iMenuSelect;
        cout << "\n";

        switch (iMenuSelect) {
        case 1: //create fighter
        {

            create(fighter);

            break;
        }
        case 2: //pick fighter
        {
            pick(fighter);

            break;
        }
        case 3: //last man standing
        {
            int fighterAmount = 0;

            for (int i = 0; i < 10; i++) {


                if (fighter[i] != 0) {

                    fighterAmount++;
                }

                cout << fighter[i] << endl;
                cout << "amount: " << fighterAmount << endl;
            }

            if (fighterAmount >= 2) {
                lastManStanding(fighter);
            }
            else {
                cout << "No or only one fighter available, please create fighters." << endl;
            }

            break;
        }
        case 4: //view fighter
        {
            view(fighter);

            break;
        }
        case 5: //delete fighter
        {
            int loeschen = 0;

            view(fighter);

            cout << "Which fighter should be deleted: " << endl;
            cin >> loeschen;



            fighter[loeschen - 1] = nullptr;

            delete fighter[loeschen - 1];

            cout << "Fighter number" << loeschen << "was deleted." << endl;

            break;

        }
        case 6: //manual
        {

            cout << "Menu: \n1. CREATE FIGHTER: Enter number of fighters to be created (1-10).\n    This is followed by a prompt for each fighter's name and class." << endl;
            cout << "2. PICK 2 FIGHTERS: Fighters number one and two must be chosen.\n    Then the previously chosen fighters fight until one dies." << endl;
            cout << "3. LAST MAN STANDING: All fighters fight against each other until only one is left." << endl;
            cout << "4. VIEW FIGHTERS: List of all fighters" << endl;
            cout << "5. DELETE FIGHTER: Delete a single fighter." << endl;
            cout << "6. MANUAL/INFO: Instructions for the user." << endl;
            cout << "7. QUIT: Program is ended. \n" << endl;

            break;
        }
        case 7: //quit
        {return 0;}

        default:   //exception handling
        {
            cout << "Entry not valid!" << endl;
        }

        }
    }


    return 0;
}

#endif