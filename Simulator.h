/*
Andrew Floyd
ID: 2429112
CPSC 350-03
Project_Level

Simulates a game of Mario
*/
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Level.h"
#include "Mario.h"
#include <string>
#include <fstream>
using namespace std;
// declare all functions of the Simulator class
class Simulator {
public:
    Simulator();
    Simulator(int levels, int levelSize, int lives, int chanceCoins, int chanceNothing, int chanceGoomba, int chanceKoopa, int chanceMushroom, string thenameofthefile);
    ~Simulator();
    void printWorld();


private:
    bool gameOver;
    int currLevel;
    int levelSize;
    int levels;
    Level* world[];
};

#endif
