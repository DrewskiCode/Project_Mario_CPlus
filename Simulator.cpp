/*
Andrew Floyd
ID: 2429112
CPSC 350-03
Project_Level

Simulates a game of Mario
*/
#include "Level.h"
#include "Simulator.h"
#include "Mario.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

        Simulator::Simulator() {
        };

        Simulator::Simulator(int levels, int levelSize, int lives, int chanceCoins, int chanceNothing, int chanceGoomba, int chanceKoopa, int chanceMushroom, string thenameofthefile) {
            // initialize member variables
            ofstream logFile;
            logFile.open(thenameofthefile);
            gameOver = false;
            currLevel = 0;
            this->levelSize = levelSize;
            this->levels = levels;
            // create mario object
            Mario myMario(levels, levelSize, lives);
            for (int i = 0; i < levels; ++i) {
                // create world array of Levels
                world[i] =  new Level(levelSize, chanceCoins, chanceNothing, chanceGoomba, chanceKoopa, chanceMushroom);
                if (i < levels - 1) {
                    world[i]->addWarpPipe(); // add warp pipe to all levels but the last one
                }
            }
            for (int i = 0; i < levels; ++i) {
              logFile << (world[i]->toString()); // print levels in world
                logFile << ("\n==========\n");
            }
            logFile << ("Mario is starting in position: (" + to_string(myMario.getMarioRow()) + "," + to_string(myMario.getMarioCol()) + ")");
          char cellValue = world[0]->getCell(myMario.getMarioRow(), myMario.getMarioCol()); // get where mario is at
            world[0]->setCell(myMario.getMarioRow(), myMario.getMarioCol(), 'H'); // set that cell on the printable level to H
            logFile << ("\n==========\n");
            int count = 0;
            while (gameOver == false) { // the big while loop that runs the game
                count++;
                world[currLevel]->setCell(myMario.getMarioRow(), myMario.getMarioCol(), 'H'); // set cell to mario char
                logFile << (world[currLevel]->toString()); // print out current world pattern
                world[currLevel]->setCell(myMario.getMarioRow(), myMario.getMarioCol(), cellValue); // set old cell to old char
                logFile << ("\n==========\n");
                logFile << ("Level: " + to_string(currLevel) + ". Mario is at position: (" + to_string(myMario.getMarioRow()) + "," + to_string(myMario.getMarioCol()) + "). Mario is at power level " + to_string(myMario.getPowerLevel()) + ". ");
    // Update the cell based on its value
    bool outcome;
    int counter;
    switch (cellValue) { // big switch statement to handle Marios interaction with the cell hes in
        case 'x': // Empty space
             logFile << ("Mario visited an empty space. Mario has " + to_string(myMario.getLives()) + " lives left. Mario has " + to_string(myMario.getCoins()) + " coins. ");
             break;
        case 'c': // Coin
            myMario.collectCoin();
            world[currLevel]->setCell(myMario.getMarioRow(), myMario.getMarioCol(), 'x');
            logFile << ("Mario collected a coin. Mario has " + to_string(myMario.getLives()) + " lives left. Mario has " + to_string(myMario.getCoins()) + " coins. ");
            break;
        case 'm': // Mushroom
            myMario.collectMushroom();
            world[currLevel]->setCell(myMario.getMarioRow(), myMario.getMarioCol(), 'x');
             logFile << ("Mario collected a mushroom. Mario has " + to_string(myMario.getLives()) + " lives left. Mario has " + to_string(myMario.getCoins()) + " coins. ");
            break;
        case 'g': // Goomba
            outcome = myMario.fightGoomba();
            if (outcome) { // check outcome from Mario class
               logFile << ("Mario encountered a Goomba and won. Mario has " + to_string(myMario.getLives()) + " lives left. Mario has " + to_string(myMario.getCoins()) + " coins. ");
               world[currLevel]->setCell(myMario.getMarioRow(), myMario.getMarioCol(), 'x');
            } else {
               logFile << ("Mario encountered a Goomba and lost. Mario has " + to_string(myMario.getLives()) + " lives left. Mario has " + to_string(myMario.getCoins()) + " coins. ");
            }
            if (myMario.getLives() == 0) { // Mario death logic
                gameOver = true;
                logFile << ("\nGAME OVER MARIO LOSES");
            }
            break;
        case 'k': // Koopa
            outcome = myMario.fightKoopa();
            if (outcome) { // check outcome from Mario class
               logFile << ("Mario encountered a Koopa and won. Mario has " + to_string(myMario.getLives()) + " lives left. Mario has " + to_string(myMario.getCoins()) + " coins. ");
               world[currLevel]->setCell(myMario.getMarioRow(), myMario.getMarioCol(), 'x');
            } else {
               logFile << ("Mario encountered a Koopa and lost. Mario has " + to_string(myMario.getLives()) + " lives left. Mario has " + to_string(myMario.getCoins()) + " coins. ");
            }
            if (myMario.getLives() == 0) { // Mario death logic
                gameOver = true;
                logFile << ("\nGAME OVER MARIO LOSES");
            }
            break;
        case 'b': // Boss
            outcome = false;
            while (outcome == false) { // loop to fight boss until Mario Wins/Dies
            outcome = myMario.fightBoss();
            if (outcome == true) {
                logFile << ("Mario encountered a boss and won. Mario has " + to_string(myMario.getLives()) + " lives left. Mario has " + to_string(myMario.getCoins()) + " coins. Mario will now PROCEED.");
                world[currLevel]->setCell(myMario.getMarioRow(), myMario.getMarioCol(), 'x');
                currLevel++;
                if (currLevel == levels) { // If the boss is on the last level, Mario wins the game
                    logFile << ("\nYou rescued the princess!");
                    gameOver = true;
                    break;
                } 
            } else {
                logFile << ("Mario encountered a boss and lost. Mario has " + to_string(myMario.getLives()) + " lives left. Mario has " + to_string(myMario.getCoins()) + " coins. Mario will stay put.");
                if (myMario.getLives() < 1) { // mario death logic
                gameOver = true;
                logFile << ("\nGAME OVER MARIO LOSES");
                break;
            }
                // print statements to manage the boss loop
                world[currLevel]->setCell(myMario.getMarioRow(), myMario.getMarioCol(), 'H');
                logFile << ("\n==========\n");
                logFile << (world[currLevel]->toString()); // print out current world pattern
                logFile << ("\n==========\n");
                logFile << ("Level: " + to_string(currLevel) + ". Mario is at position: (" + to_string(myMario.getMarioRow()) + "," + to_string(myMario.getMarioCol()) + "). Mario is at power level " + to_string(myMario.getPowerLevel()) + ". ");
            }
            }
            
            break;
        case 'w': // Warp pipe
            myMario.warpPipe();
            logFile << ("Mario encountered a warp pipe. Mario has " + to_string(myMario.getLives()) + " lives left. Mario has " + to_string(myMario.getCoins()) + " coins. Mario will now WARP.");
            currLevel++;
            break;
        default:
            // Handles other values or errors
            break;
    }
     char temp = cellValue; // just for logging purposes
     string move = myMario.move(levelSize);
     if ((temp == 'k' || temp == 'g' || temp == 'm' || temp == 'c') && gameOver == false) {
     logFile << ("Mario will move " + move + ".");
     }
     logFile << ("\n==========\n");
     if (gameOver == false) {
        cellValue = world[currLevel]->getCell(myMario.getMarioRow(), myMario.getMarioCol());
     } // set new cell value and keep the loop going

    }
    logFile.close(); // once game has ended, close log file
    }
        Simulator::~Simulator() {
}


       