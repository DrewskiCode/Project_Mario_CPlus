/*
Andrew Floyd
ID: 2429112
CPSC 350-03
Project_Mario

Main function to execute Simulator
*/
#include "Simulator.h"
#include "Level.h"
#include "Mario.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    // check for correct use of command line arguements
        if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
    }

    // set filename and logfile to variables
    const string filename = argv[1];
    string thenameofthefile = argv[2];
    ifstream inputFile(filename);

    // check if file is not open
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the file " << filename << endl;
    }

    int values[8];  // Array to store the 8 values
    for (int i = 0; i < 8; ++i) {
        if (!(inputFile >> values[i])) {
            cerr << "Error reading value " << i + 1 << " from the file." << endl;

        }
    }

    // Check if the percentages sum to 100
    int totalPercentage = values[3] + values[4] + values[5] + values[6] + values[7];
    if (totalPercentage != 100) {
       cerr << "Error: Percentages on lines 4-8 do not sum to 100." << endl;
    }
    Simulator(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], thenameofthefile); // Call Simulator Function
    inputFile.close();
    cout << "Simulation Complete" << endl;
    return 0;
}