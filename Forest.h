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
<<<<<<< HEAD
        string rooms[7] = {"Start Room", "Room 1", "Room 2", "Room 3", "Room 4", "Room 5", "Fight Room"};
        string currentRoom;
        bool gameOver;
    public:
=======
        string rooms[7];        // Room names
        string currentRoom;      // Current room of the player
        string*** roomItems;     // Pointer to an array of pointers for items in the rooms
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
>>>>>>> origin/main
        void handleStartLine();
        void handleRoom1and2();
        void handleRoom3();
        void handleRoom4and5();
        void handleFightRoom();
};

#endif