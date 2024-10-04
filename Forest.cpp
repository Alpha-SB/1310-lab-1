#include "Forest.h"

Forest::Forest() : currentRoom("Start Room"), gameOver(false)
{
    rooms[0] = "Start Room";
    rooms[1] = "Room 1";
    rooms[2] = "Room 2";
    rooms[3] = "Room 3";
    rooms[4] = "Room 4";
    rooms[5] = "Room 5";
    rooms[6] = "Fight Room";

    roomItems = new string*[7];//

   /* for (int i = 0; i < 7; ++i) 
    {
        roomItems[i] = new string[2];
    }

    roomItems[1][0] = "Map";
    roomItems[1][1] = "Key";

    roomItems[2][0] = "Sword";
    roomItems[2][1] = "Shield";

    roomItems[4][0] = "Healing Potion";
    roomItems[4][1] = "Armor";

    roomItems[5][0] = "Bow";
    roomItems[5][1] = "Arrows";
}

/*Forest::~Forest() 
{
    for (int i = 0; i < 7; ++i) 
    {
        delete roomItems[i];
    }
    delete[] roomItems;
}*/

void Forest::displayCurrentRoom() 
{
    cout << "\nYou are currently in " << currentRoom << endl;
    //displayRoomItems();//
}

/*void Forest::displayRoomItems() 
{
    int roomIndex = getRoomIndex(currentRoom);
    if (roomIndex != -1) 
    {
        cout << "Items in this room: " << roomItems[roomIndex][0] << ", " << roomItems[roomIndex][1] << endl;
    }
}*/

int Forest::getRoomIndex(const string& room) 
{
    for (int i = 0; i < 7; ++i) 
    {
        if (rooms[i] == room) 
        {
            return i;
        }
    }
    return -1;  // Room not found
}

void Forest::startGame() 
{
    while (!gameOver) 
    {
        if (currentRoom == "Start Room") 
        {
            handleStartLine();
        } 
        else if (currentRoom == "Room 1" || currentRoom == "Room 2") 
        {
            handleRoom1and2();
        } 
        else if (currentRoom == "Room 3") 
        {
            handleRoom3();
        } 
        else if (currentRoom == "Room 4" || currentRoom == "Room 5") 
        {
            handleRoom4and5();
        } 
        else if (currentRoom == "Fight Room") 
        {
            handleFightRoom();
        }
    }
}

void Forest::handleStartLine() 
{
    int input;
    do
    {
        displayCurrentRoom();
        cout << "What would you like to do?" << endl;
        cout << "1: to Go to Room 1" << endl;
        cout << "2: to Go to Room 2" << endl;
        cin >> input;
    }
    while (input != 1 && input != 2);
    currentRoom = rooms[input];
}

void Forest::handleRoom1and2() 
{
    int input;
    do
    {
        displayCurrentRoom();
        cout << "What would you like to do?" << endl;
        cout << "3: to Go to Room 3" << endl;
        cin >> input;
    }
    while (input != 3);
    currentRoom = rooms[input];
}

void Forest::handleRoom3() 
{
    int input;
    do
    {
        displayCurrentRoom();
        cout << "What would you like to do?" << endl;
        cout << "4: to Go to Room 4" << endl;
        cout << "5: to Go to Room 5" << endl;
        cin >> input;
    }
    while (input != 4 && input != 5);
    currentRoom = rooms[input];
}

void Forest::handleRoom4and5() 
{
    int input;
    do
    {
        displayCurrentRoom();
        cout << "Enter 6 to go to the Boss Fight" << endl;
        cin >> input;
    }
    while (input != 6);
    currentRoom = "Fight Room";
}

void Forest::handleFightRoom() 
{
    displayCurrentRoom();
    cout << "You have reached the end of the game!" << endl;
    gameOver = true;
}
