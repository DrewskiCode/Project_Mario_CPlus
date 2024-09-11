/*
Andrew Floyd
ID: 2429112
CPSC 350-03
Project_Level

Creates object Mario and includes all outcomes for his movement
*/
#include <ctime>
#include <cstdlib>
#include "Level.h"
#include "Mario.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

        Mario::Mario() {
        };

        Mario::Mario(int levels, int levelSize, int lives) { // initialize member variables for a mario object
           srand(static_cast<unsigned int>(time(nullptr)));
           enemysDefeated = 0;
           coins = 0;
           powerLevel = 0;
           this->lives = lives;
                row = rand() % 5; // Random number between 0 and 4
                col = rand() % 5; // Random number between 0 and 4
            
        };

         Mario::~Mario() {
        };

        void Mario::collectCoin() { // collect a coin, if 20, add life and set coins to zero
            coins++;
            if (coins == 20) {
                lives++;
                coins = 0;
            }
        }

        void Mario::collectMushroom() { // collect mushroom, powerlevel plus one if powerlevel isnt already two
            if (powerLevel != 2) {
                powerLevel++;
            }
        }

        bool Mario::fightGoomba() {
            int randomNumber = rand() % 100 + 1;
            if (randomNumber > 20) {
                // mario defeats goomba
                enemysDefeated++;
                if (enemysDefeated == 7) {
                    lives++;
                    enemysDefeated = 0;
                }
                return true;
            } else {
                // goomba defeats mario
                powerLevel--;
                if (powerLevel < 0){
                    lives--;
                    powerLevel = 0;
                    enemysDefeated = 0;
                }
                return false;
            }
        }

        bool Mario::fightKoopa() {
          //  srand(static_cast<unsigned int>(time(nullptr)));
            int randomNumber = rand() % 100 + 1;
            if (randomNumber > 35) {
                // mario defeats koopa
                enemysDefeated++;
                if (enemysDefeated == 7) {
                    lives++;
                    enemysDefeated = 0;
                }
                return true;
            } else {
                // koopa defeats mario
                powerLevel--;
                if (powerLevel < 0) {
                    lives--;
                    powerLevel = 0;
                    enemysDefeated = 0;
                }
                return false;
            }
        }

        bool Mario::fightBoss() { // fix percentages (((add case for losing to boss, and add move up a level in simulator)))
            int randomNumber = rand() % 100 + 1;
            if (randomNumber > 50) {
                // mario defeats boss
                enemysDefeated++;
                if (enemysDefeated == 7) {
                    lives++;
                    enemysDefeated = 0;
                }
                return true;
            } else {
                // boss defeats mario
                powerLevel = powerLevel - 2;
                if (powerLevel < 0) {
                    lives--;
                    enemysDefeated = 0;
                    powerLevel = 0;
                }
                return false;
            }
        }

        void Mario::warpPipe() {
                row = rand() % 5; // Random number between 0 and 4
                col = rand() % 5; // Random number between 0 and 4
        }

        int Mario::getMarioRow() {
            return row;
        }

        int Mario::getMarioCol() {
            return col;
        }

        string Mario::move(int levelSize) {
    // Generate a random direction: 0 for left, 1 for right, 2 for down, 3 for up
        int direction = rand() % 4;

    // Update the row and col based on the selected direction
    switch (direction) {
        case 0: // Left
            col--;
            if (col < 0) {
                col = levelSize - 1;
            } else {
            }
            return "LEFT";
        case 1: // Right
            col++;
            if (col > levelSize - 1) {
                col = 0;
            } else {
            }
            return "RIGHT";
        case 2: // Down
            row++;
            if (row > levelSize - 1) {
                row = 0;
            } else {
            }
            return "DOWN";
        case 3: // Up
            row--;
            if (row < 0) {
                row = levelSize - 1;
            } else {
            }
            return "UP";
    }
    return "Error";
    
}

int Mario::getLives() {
        return lives;
    }

int Mario::getPowerLevel() {
    return powerLevel;
}

int Mario::getCoins() {
    return coins;
}
