#ifndef FOREST_H
#define FOREST_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <climits>

using namespace std;
class Forest 
{
    private:
        string rooms[7];        // Room names
        string currentRoom;      // Current room of the player
        string** roomItems;     // Pointer to an array of pointers for items in the rooms
        bool gameOver;           // Game state flag

    public:
        // Constructor and Destructor
        Forest();
        ~Forest();

        // Public Methods
        void displayCurrentRoom();
        void startGame();

    private:
        // Private Helper Methods
        void displayRoomItems();
        int getRoomIndex(const string& room);
        void handleStartLine();
        void handleRoom1and2();
        void handleRoom3();
        void handleRoom4and5();
        void handleFightRoom();
};

#endif