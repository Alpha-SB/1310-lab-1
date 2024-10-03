#include <iostream>
#include<fstream> //used to read from and write to text files
#include<string>
#include<iomanip>
#include<cctype>
#include<climits>

using namespace std;

class Forest 
{
    private:
        string rooms[7] = {"Start Room", "Room 1", "Room 2", "Room 3", "Room 4", "Room 5", "Fight Room"};
        
        string currentRoom;
        bool gameOver;

    public:
        Forest() : currentRoom("Start Room"), gameOver(false) {}  // Constructor to initialize game
        
        ~Forest()
        {

        }

        void displayCurrentRoom() 
        {
            cout << "\nYou are currently in " << currentRoom << endl;
        }

        void startGame() 
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

    private:
        void handleStartLine() 
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

        void handleRoom1and2() 
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

        void handleRoom3() 
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

        void handleRoom4and5() 
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

        void handleFightRoom() 
        {
            displayCurrentRoom();
            cout << "You have reached the end of the game!" << endl;
            gameOver = true;
        }
};