/*
Andrew Floyd
ID: 2429112
CPSC 350-03
Project_Level

Creates object Mario and includes all outcomes for his movement
*/
#include <iostream>
#include <string>
#ifndef MARIO_H
#define MARIO_H
using namespace std;
// declare all functions of the Mario class
class Mario {
    public:
        Mario();
        Mario(int levels, int levelSize, int lives);
        ~Mario();

        void collectCoin();
        bool fightGoomba();
        bool fightKoopa();
        bool fightBoss();
        void warpPipe();
        void collectMushroom();
        int getMarioCol();
        int getMarioRow();
        string move(int levelSize);
        int getLives();
        int getPowerLevel();
        int getCoins();


            
    private:
        int levelSize;
        int lives;
        int powerLevel;
        int coins;
        int row;
        int col;
        int enemysDefeated;
};

#endif