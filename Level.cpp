/*
Andrew Floyd
ID: 2429112
CPSC 350-03
Project_Level

Create a level
*/
#include "Level.h"
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

        Level::Level() {
        }

        Level::Level(int levelSize, int chanceCoin, int chanceNothing, int chanceGoomba, int chanceKoopa, int chanceMushroom) {
              this->levelSize = levelSize;
               level = new char*[levelSize]; // creating a 2D char array
            for (int i = 0; i < levelSize; ++i) {
                level[i] = new char[levelSize];
                for (int j = 0; j < levelSize; ++j) {

                    int randomValue = ((int)rand() % 100) + 1; // Generate a random value between 1 and 100

                    // Determine the character based on the chances
                    if (randomValue < chanceCoin) {
                        level[i][j] = 'c'; // Coin
                    } else if (randomValue < chanceCoin + chanceNothing) {
                        level[i][j] = 'x'; // Empty space
                    } else if (randomValue < chanceCoin + chanceNothing + chanceGoomba) {
                        level[i][j] = 'g'; // Goomba
                    } else if (randomValue < chanceCoin + chanceNothing + chanceGoomba + chanceKoopa) {
                        level[i][j] = 'k'; // Koopa
                    } else {
                        level[i][j] = 'm'; // Mushroom
                    }
                }
            }

            int randomValue1 = ((int)rand() % levelSize);
            int randomValue2 = ((int)rand() % levelSize);

            level[randomValue1][randomValue2] = 'b'; // place the boss on each level
            
        };

         Level::~Level() { // Level destructor
            for (int i = 0; i < levelSize; ++i) {
                delete[] level[i];
            }
            delete[] level;
        };

        int Level::getLevelSize() {
            return levelSize;
        }

        void Level::setLevelSize(int newLevelSize) {
            levelSize = newLevelSize;
        }
        char Level::getCell(int row, int col) { // get the cell in a level
            if (row >= 0 && row < levelSize && col >= 0 && col < levelSize) {
        return level[row][col];
            }
        return 'E';
    }
        void Level::setCell(int row, int col, char newValue) { // set the cell to a new value in a level
            if (row >= 0 && row < levelSize && col >= 0 && col < levelSize) {
        level[row][col] = newValue;
            }
    }

    string Level::toString() { // output string of a level
        string str = "";
       for (int i = 0; i < levelSize; ++i) {
                for (int j = 0; j < levelSize; ++j) {
                    if (i >= 0 && i < levelSize && j >= 0 && j < levelSize) {
                        str += level[i][j];
                    }
                }
                if (i < levelSize - 1) {
                    str += "\n"; // Add newline only if it's not the last line
                }
            }
        return str;
    }
        void Level::addWarpPipe() {
            int randomValue3 = -1; // Initialize to a value outside bounds
            int randomValue4 = -1; // Initialize to a value outside bounds

            do {
                randomValue3 = ((int)rand() % levelSize);
                randomValue4 = ((int)rand() % levelSize);

            } while (level[randomValue3][randomValue4] == 'b'); // check to see that its not on the boss square

            
            level[randomValue3][randomValue4] = 'w'; // Assign 'w' to a valid position
        }