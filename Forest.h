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
    string rooms[7] = {"Start Room", "Room 1", "Room 2", "Room 3", "Room 4", "Room 5","Fight Room"};
    string currentRoom;
    bool gameOver;
public:
    Forest () : currentRoom("Start Room"), gameOver(false){} 
};

#endif