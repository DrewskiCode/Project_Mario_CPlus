/*
Andrew Floyd
ID: 2429112
CPSC 350-03
Project_Level

Create a level
*/
#include <string>
#ifndef LEVEL_H
#define LEVEL_H
using namespace std;
// declare all functions of the Level class
class Level {
    public:
        Level();
        Level(int levelSize, int chanceCoin, int chanceNothing, int chanceGoomba, int chanceKoopa, int chanceMushroom);
        ~Level();
        int getLevelSize();
        void setLevelSize(int newLevelSize);
        string toString();
        char getCell(int row, int col);
        void setCell(int row, int col, char newValue);
        void addWarpPipe();

            
    private:
        int levelSize;
        int chanceCoin;
        int chanceMushroom;
        int chanceEnemy;
        int chanceNothing;
        char** level;
};

#endif