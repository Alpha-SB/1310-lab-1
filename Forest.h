#ifndef FOREST_H
#define FOREST_H

#include<iostream>
#include<fstream> 
#include<string>
#include<iomanip>
#include<cctype>
#include<climits>
using namespace std;
class Forest 
{
    private:
        string rooms[7];
        string currentRoom;
        string*** roomItems;
        bool gameOver;

    public:
        // Constructor and Destructor
        Forest();
        ~Forest();

        void displayCurrentRoom();
        void startGame();

    private:
        void displayRoomItems();
        int getRoomIndex(const string& room);
        void handleStartLine();
        void handleRoom1and2();
        void handleRoom3();
        void handleRoom4and5();
        void handleFightRoom();
};

#endif
