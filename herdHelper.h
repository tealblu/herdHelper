#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class herdClass {
    public:
        string name; // Name of the creature
        int totalHealth; // Total health of the pack
        int indivHealth; // Health of each individual creature
        int numIndiv; // Number of individual creatures
        // To access attack number of dice: attackList[i].second.first
        // To access dice type: attackList[i].second.second
        vector<pair<string, pair<int,int>>> attackList; // attackName, attackDamage is the pair
};

// This function prints the menu
int printMenu(void);

// This function sets up the herd
herdClass createHerd(void);

// This function prints herd info
void printHerdInfo(herdClass herdObj);

// Rolls dice. 
int rollDice(int numDice, int numSides);

// Prints list of attacks
void printAttacks(herdClass herdObj);

// Attacks with the herd
void attack(herdClass herdObj);

// Heals the herd
herdClass heal(herdClass herdObj);

// Damages the herd
herdClass damage(herdClass herdObj);