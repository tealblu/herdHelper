#include "herdHelper.h"

int printMenu(void) {
    // Print the menu
    cout << "MAIN MENU:" << endl;
    cout << "   1. Attack using the herd" << endl;
    cout << "   2. Damage the herd" << endl;
    cout << "   3. Heal the herd" << endl;
    cout << "   4. Print herd info" << endl;
    cout << "   5. Roll misc dice" << endl;
    cout << "   6. Quit" << endl;

    // Collect choice
    int choice = 0;
    cin >> choice;

    return choice;
}

herdClass createHerd(void) {
    // Create the herd!
    cout << "Time to create your herd!" << endl;
    herdClass herdObj;

    // Name
    cout << "What is the name of the creature?" << endl;
    cin >> herdObj.name;

    // Health
    cout << "How much health does each individual have?" << endl;
    cin >> herdObj.indivHealth;

    // Number of individuals
    cout << "How many " << herdObj.name << "s are in the herd?" << endl;
    cin >> herdObj.numIndiv;

    herdObj.totalHealth = herdObj.numIndiv * herdObj.indivHealth;

    // Attacks
    int numAttacks;
    cout << "How many attacks would you like to add?" << endl;
    cin >> numAttacks;

    for(int i = 1; i <= numAttacks; i++) {
        string attackName;
        int numDice, numSides;


        cout << "What is the name of Attack " << i << " ?" << endl;
        cin >> attackName;
        cout << "How many attack dice should be rolled?" << endl;
        cin >> numDice;
        cout << "How many sides are on the attack dice?" << endl;
        cin >> numSides;

        // Add attack info to the vector
        herdObj.attackList.push_back({attackName,{numDice,numSides}});

        // Move on
        cout << "Done with Attack " << i << "." << endl;
    }

    return herdObj;
}

void printHerdInfo(herdClass herdObj) {
    cout << "--------HERD INFO--------" << endl;

    cout << "Name: " << herdObj.name << endl;
    cout << "Collective health: " << herdObj.totalHealth << endl;
    cout << "Number alive: " << herdObj.numIndiv << endl;

    cout << "-------------------------" << endl << endl;
}

int rollDice(int numDice, int numSides) {
    int result = 0;

    // Roll the dice
    for(int i = 0; i < numDice; i++) {
        result += (rand() % numSides) + 1;
    }

    return result;
}

void printAttacks(herdClass herdObj) {
    vector<pair<string, pair<int,int>>> attacks = herdObj.attackList; // to ease readability
    cout << endl << endl << "-------ATTACK LIST-------" << endl;
    for(unsigned int i = 0; i < attacks.size(); i++) {
        cout << i+1 << ". " << attacks[i].first << endl;
        cout << "   Number of attack dice: " << attacks[i].second.first << endl;
        cout << "   Attack dice type: d" << attacks[i].second.second << endl;
    }
    cout << "-------------------------" << endl;
}

void attack(herdClass herdObj) {
    // Print the list of attacks
    printAttacks(herdObj);

    // Select the attack
    int attackNum;
    cout << "Please pick an attack using the number next to its name:" << endl;
    cin >> attackNum;

    // Adjust attackNum
    attackNum--;

    // Set up the dice
    int numDice, numSides;
    numDice = herdObj.attackList[attackNum].second.first;
    numSides = herdObj.attackList[attackNum].second.second;

    // Roll dice!
    int result = 0;
    for(int i = 0; i < herdObj.numIndiv; i++) {
        result += rollDice(numDice, numSides);
    }

    // Print the result
    cout << "The result is: " << result << endl;
}

herdClass heal(herdClass herdObj) {
    int healAmt, maxHP;

    // Calculate max possible health
    maxHP = herdObj.indivHealth * herdObj.numIndiv;

    // Capture user input
    cout << "How many hit points should be added to the herd?" << endl;
    cin >> healAmt;

    // Add the hit points into the total health pool
    herdObj.totalHealth += healAmt;

    // If health is too large, set it to max possible health
    if(herdObj.totalHealth > maxHP) {
        herdObj.totalHealth = maxHP;
    }

    cout << "Total health is now: " << herdObj.totalHealth << endl;

    return herdObj;
}

herdClass damage(herdClass herdObj) {
    int dmg;

    // Capture user input
    cout << "How much damage should be applied?" << endl;
    cin >> dmg;

    // Kill off creatures
    while(dmg > herdObj.indivHealth) {
        // Subtract one creature from total health pool
        herdObj.totalHealth -= herdObj.indivHealth;
        // Subtract that amount from dmg counter
        dmg -= herdObj.indivHealth;
        // Remove a creature
        herdObj.numIndiv--;
    }

    // Apply the remaining damage
    herdObj.totalHealth -= dmg;

    // Fix negative numbers
    if(herdObj.totalHealth <= 0) {
        herdObj.totalHealth = 0;
        herdObj.numIndiv = 0;
        cout << "Your group is dead! Rip." << endl;
    }

    // Print status
    printHerdInfo(herdObj);

    return herdObj;
}