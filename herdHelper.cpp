/* This is a program to help manage groups of animals
    for animal summoning in D&D. */

#include "herdHelper.h"

int main(void) {
    // Intro message
    cout << "Welcome to Herd Helper!" << endl;
    cout << "Please read the ReadMe if you don't know how to use this." << endl;
    cout << "This game is NOT D&D, it is designed to be used WITH D&D." << endl;
    cout << "Have fun!" << endl << endl << endl;

    // Create the herd
    herdClass herdObj = createHerd();

    // Main loop (menu and stuff)
    bool loop = 1;
    do {
        // Create space
        cout << endl;

        // Run the menu!
        switch(printMenu()) {
            case 1:
                // Attack using the herd
                attack(herdObj);
                break;
            case 2:
                // Damage the herd
                herdObj = damage(herdObj);
                break;
            case 3:
                // Heal the herd
                herdObj = heal(herdObj);
                break;
            case 4:
                // Print herd info
                printHerdInfo(herdObj);
                break;
            case 5:
                // Roll misc dice
                int numDice, numSides;
                cout << "How many dice should be rolled?" << endl;
                cin >> numDice;
                cout << "How many sides does each dice have?" << endl;
                cin >> numSides;

                cout << "The result is: " << rollDice(numDice, numSides) << endl;

                break;
            case 6:
                // Quit
                cout << "Have a nice day!" << endl;
                loop = 0;
            default:
                cout << "Please enter one of the numbers listed next to the menu choices!" << endl;
        }
    } while(loop == 1);

    // Exit, signaling program success
    return EXIT_SUCCESS;
}