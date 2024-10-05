#ifndef FOREST_H
#define FOREST_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <climits>
#include "Character.h"
#include "Interactions.h"
using namespace std;
class Forest 
{
    private:
        string currentRoom;      // Current room of the player
        string** roomItems;     // Pointer to an array of pointers for items in the rooms//
        bool gameOver;           // Game state flag

    public:
        // Constructor and Destructor
        Forest();
        ~Forest();
        int handleStartLine();
        int handleRoom3();
        int runGame(int, Character*);//runs the game and directs where the player goes. 
    
};

#endif