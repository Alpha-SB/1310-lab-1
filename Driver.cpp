/*
    Title: Program One
	Authors: Sawyer Blanchford, Anthony Cosentino, Zachary Jones, Gabe Simpkins, and Chris Wilson
	Date: 9/16/2024
	Purpose: 
*/

#include <iostream>
#include<fstream> //used to read from and write to text files
#include<string>
#include<iomanip>
#include<cctype>
#include<climits>
#include"Interactions.h"
#include "Character.h"
#include "HelperFunctions.cpp"
#include "Forest.h"

using namespace std;

int main ()
{
    int choice = 0,startingPoint = 1, CharacterSelect; //these numbers are used for user input choices and sets the starting point
    bool cont = true; //determines if the program loops again
    string fileName, UserName, startingPointString; // used to name and locate names of text files and the users character name
    ifstream inFile; // used to read from text files
    ofstream outFile; // used to write to text files
    
    Character **Player;
    const int maxCharacters = 5;
    Player = new Character*[maxCharacters];
    Character **PrintC;
    PrintC = Player;
    Interactions game; //obj to run interactions functions
     

    //ascii art of game title
    cout << " _______   __    __  .__   __.   _______  _______   ______   .__   __.      _______      ___      .___  ___.  _______ " << endl;
    cout << "|       \\ |  |  |  | |  \\ |  |  /  _____||   ____| /  __  \\  |  \\ |  |     /  _____|    /   \\     |   \\/   | |   ____|" << endl;
    cout << "|  .--.  ||  |  |  | |   \\|  | |  |  __  |  |__   |  |  |  | |   \\|  |    |  |  __     /  ^  \\    |  \\  /  | |  |__   " << endl;
    cout << "|  |  |  ||  |  |  | |  . `  | |  | |_ | |   __|  |  |  |  | |  . `  |    |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  " << endl;
    cout << "|  '--'  ||  `--'  | |  |\\   | |  |__| | |  |____ |  `--'  | |  |\\   |    |  |__| |  /  _____  \\  |  |  |  | |  |____ " << endl;
    cout << "|_______/  \\______/  |__| \\__|  \\______| |_______| \\______/  |__| \\__|     \\______| /__/     \\__\\ |__|  |__| |_______|" << endl;
                
    do{
        
        cout << "\n\n\nselect option:\n(1)\t\t(2)\t\t(3)\t\t(any other number)";
        cout << "|START NEW GAME|\t|START LOAD GAME|\t|DELETE SAVE|\t|QUIT PROGRAM|";

        int choice;
        choice = checkInput(choice);
        
        switch (choice){
            case 1:

                choice = 1;

                cout << "Name New Save File: (Ex. File_Name.txt)";
                cin >> fileName;

                for (int i = 0; i < fileName.length(); i++)  //replaces spaces with underscore
                    if (fileName[i] == ' ')
                        fileName[i] = '_';
                
                //this is the character selection screen
                cout << "\nName your character: ";
                getline(cin,UserName);
                cout << "\nWhat kind of character would you like to be?" << endl;
                cout << "\t1: Tank, more HP less attack and slower" << endl;
                cout << "\t2. Knight, balance of HP, attack, and speed" << endl;
                cout << "\t3. glass cannon, less HP, more attack, much faster" << endl;
                cin >> CharacterSelect;

                switch (CharacterSelect){
                    case 1:
                        //Character name and other data for each class in each case ;
                        //selectCharacter(UserName, 175, 25, 3);
                        Player[0]->CreateCharacter(UserName, 175, 25, 3, 0); 
                    case 2:
                        //selectCharacter(UserName, 150, 50, 6);
                        Player[0]->CreateCharacter(UserName, 175, 50, 6, 0);
                    case 3:
                        //selectCharacter(UserName, 125, 75, 9);
                        Player[0]->CreateCharacter(UserName, 125 , 75, 9, 0);
                }   

                Player[1]->CreateCharacter("Private Joey", 75, 25, 6, 0);
                Player[2]->CreateCharacter("Commander John", 125, 50, 3, 0);
                Player[3]->CreateCharacter("General Wes", 100, 75, 5, 0);
                Player[4]->CreateCharacter("King Vandergriff", 150, 75, 5, 0);
                //this section runs the actual game
                do 
                {
                    startingPoint = game.runGame(startingPoint, *Player);
                    if (startingPoint == 0)
                        break;
                    if (startingPoint == 8)
                        break;
                    
                    cout << "\nWould you like to continue? Yes(1) or No (2)";
                    cin >> choice;
                    choice = checkInput(choice); 
                }   while (choice == 1);
                if (startingPoint == 0)
                        break;
                if (startingPoint == 8){
                    cout << "Congrats you beat the game!! see you next time, " << UserName << endl;
                    
                    outFile.open(fileName); 
                    outFile << ""; // should clear file
                    outFile.close();
                    break;
                }
                outFile.open(fileName, ios::app); //opens save text file

                outFile << *(Player[0]);

                for (int i =0; i < /*numitems*/ 1;i++){
                    outFile << *(Player[0]);//need a num items functions - sawyer 
                    outFile << "#";
                }
                outFile << startingPoint << "#";
                outFile.close();

                inFile.close();
                break;

            case 2:
                choice = 1;

                while (!inFile.is_open()){
                    cout << "Which save file would you like to open? (Ex. File_Name.txt)";
                    cin >> fileName;
                    inFile.open(fileName);
                    if (inFile.is_open())
                        break;
                    cout << "\nNo file with that name exists. Try again? Yes(1) or No (2)\n";
                    choice = checkInput(choice);
                    if (choice != 1)
                        break;
                }
                if (choice != 1)
                        break;

                //reads in the starting point from the end of the file, without reading in unneed data 
                inFile.open(fileName);
                inFile.seekg(-2, ifstream::end);//this looks bad, but I promise this is the most efficient way of getting the starting point
                getline(inFile, startingPointString, '#'); 
                if (inFile.good())
                    startingPoint =  stoi(startingPointString);
                inFile.close();
                //this section runs the actual game, assuming it has been opened
                do {
                    game.runGame(startingPoint, *Player);
                    if (startingPoint == 0)
                        break;
                    if (startingPoint == 7)
                        break;
                    
                    cout << "\nWould you like to continue? Yes(1) or No (2)";
                    cin >> choice;
                    choice = checkInput(choice);
                }   while (choice == 1);
                if (startingPoint == 0)
                        break;
                if (startingPoint == 7){
                    cout << "Congrats you beat the game!! see you next time, " << UserName << endl;
                    
                    outFile.open(fileName); 
                    outFile << ""; // should clear file
                    outFile.close();
                    break;
                }
                outFile.open(fileName, ios::app); //opens save text file

                outFile << *(Player[0]);

                for (int i =0; i < /*numitems*/ 1;i++){
                    outFile << *(Player[0]);//need a num items functions - Sawyer 
                    outFile << "#";
                }
                outFile << startingPoint << "#";
                outFile.close();

                inFile.close();
                break;

            case 3:
                choice = 1;

                while (!outFile.is_open()){
                    cout << "Which save file would you like to delete? (Ex. File_Name.txt)";
                    cin >> fileName;
                    outFile.open(fileName);
                    if (outFile.is_open())
                        break;
                    cout << "\nNo file with that name exists. Try again? Yes(1) or No (2)\n";
                    choice = checkInput(choice);
                    if (choice != 1)
                        break;
                }
                if (!outFile.is_open())
                    break;
                
                outFile << ""; // should clear file
                
                //Save file template: name#numHP#numAP#numSP#numitems#itemName#numlevel#
                //Save file  example: Brandon Vandy#143#10#998#2#Brandons Shit sword#Brandons mid ass bow#7#

                outFile.close();
                break;
            default:
                choice = 4;
        }

    }while (choice == 4);
    
    cout << "\nThanks for playing...\n";
    cout << " _______   __    __  .__   __.   _______  _______   ______   .__   __.      _______      ___      .___  ___.  _______ " << endl;
    cout << "|       \\ |  |  |  | |  \\ |  |  /  _____||   ____| /  __  \\  |  \\ |  |     /  _____|    /   \\     |   \\/   | |   ____|" << endl;
    cout << "|  .--.  ||  |  |  | |   \\|  | |  |  __  |  |__   |  |  |  | |   \\|  |    |  |  __     /  ^  \\    |  \\  /  | |  |__   " << endl;
    cout << "|  |  |  ||  |  |  | |  . `  | |  | |_ | |   __|  |  |  |  | |  . `  |    |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  " << endl;
    cout << "|  '--'  ||  `--'  | |  |\\   | |  |__| | |  |____ |  `--'  | |  |\\   |    |  |__| |  /  _____  \\  |  |  |  | |  |____ " << endl;
    cout << "|_______/  \\______/  |__| \\__|  \\______| |_______| \\______/  |__| \\__|     \\______| /__/     \\__\\ |__|  |__| |_______|" << endl;
                

    return 0;


/*
    string **RoomN;
    RoomN = new string*[5];
    RoomN[1] = new string[5]; 
    RoomN[1][5];             //////What is this for? - Chris 
    */
}