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
        bool gameOver;

    public:
        Forest();  // Constructor declaration

        void displayCurrentRoom();
        void startGame();

    private:
        void handleStartLine();
        void handleRoom1and2();
        void handleRoom3();
        void handleRoom4and5();
        void handleFightRoom();
};

#endif