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
        string** roomItems;// Pointer to an array of pointers for items in the rooms//
        const int numrooms = 7;// number of rooms in game 
        int numItems = 3;// maximum possible items in a room
    public:
        // Constructor and Destructor
        Forest();
        ~Forest();
        string getroomItem(int,int);
        int handleStartLine();
        int handleRoom3();
        int runGame(int, Character*);//runs the game and directs where the player goes. 
    
};

#endif