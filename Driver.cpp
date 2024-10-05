/*
    Title: Program One
	Authors: Sawyer Blanchford, Anthony Cosentino, Zachary Jones, Gabe Simpkins, and Chris Wilson
	Date: 9/16/2024
	Purpose: 
*/

#include <iostream>
#include <fstream> //used to read from and write to text files
#include <string>
#include <iomanip>
#include <cctype>
#include <climits>
#include "Interactions.h"
#include "Character.h"
#include "Forest.h"



using namespace std;

int main()
{
    int choice =1,startingPoint = 1, CharacterSelect; //these numbers are used for user input choices and sets the starting point
    bool cont = true; //determines if the program loops again
    string fileName, UserName, grabberString; // used to name and locate names of text files and the users character name
   
    ifstream inFile; // used to read from text files
    ofstream outFile; // used to write to text files
    Interactions *I;
    Character **Player;
    const int maxCharacters = 5;
    Player = new Character*[maxCharacters];
    Character c; //used to call getter and setter functions from Character.cpp
    Character **PrintC;
    PrintC = Player;
  //  Forest* game; //obj to run interactions functions
  //  game = new Forest(); 
    Forest *F;
   
     

    //ascii art of game title

    cout <<R"( 
    _______     __    __  .__    __.   _______   _______    ______    .__    __.      _______      ___        .___   ___.  _______ 
    |       \\ |  |  |  | |  \\ |  |  /  _____| |   ____|  /  __  \\  |  \\ |  |     /  _____|    /   \\      |   \\/   | |   ____|
    |  .--.  | |  |  |  | |   \\|  | |  |  __   |  |__    |  |  |  |  |   \\|  |    |  |  __     /  ^  \\     |  \\  /  | |  |__   
    |  |  |  | |  |  |  | |  . `   | |  | |_ |  |   __|   |  |  |  |  |  . `   |    |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  
    |  '--'  | |  `--'  | |  |\\   | |  |__| |  |  |____  |  `--'  |  |  |\\   |    |  |__| |  /  _____  \\   |  |   |  | |  |____ 
    |_______/  \\______/  |__| \\__| \\______|  |_______| \\______/   |__| \\__|    \\______| /__/     \\__\\ |__|   |__| |_______|)" << endl;
              
   do{
        
        cout << "\n\n\nselect option:\n(1)\t|START NEW GAME|\n(2)\t|START LOAD GAME|\n(3)\t|DELETE SAVE|\n(any other number)\t|QUIT PROGRAM|\n";
        
        cin >> choice;
       // choice = I.checkInput(choice);
        
        switch (choice){
            case 1:

                

                cout << "Name New Save File: (Ex. File_Name.txt)\n";
                cin >> fileName;

                for (int i = 0; i < fileName.length(); i++)  //replaces spaces with underscore
                    if (fileName[i] == ' ')
                        fileName[i] = '_';
            
                cin.ignore();
                //this is the character selection screen
                cout << "\nName your character: ";
                getline(cin,UserName);
                cout << "\nWhat kind of character would you like to be?" << endl;
                cout << "\t1: Tank, more HP less attack and slower" << endl;
                cout << "\t2. Knight, balance of HP, attack, and speed" << endl;
                cout << "\t3. Rouge, less HP, more attack, much faster test" << endl;
                cin >> CharacterSelect;
           
                switch (CharacterSelect){
                    case 1:
                        //Character name and other data for each class in each case ;
                        Player[0] = new Character(UserName, 175, 25, 3, 0);
                        break;
                    case 2:
                        //selectCharacter(UserName, 150, 50, 6);
                        Player[0] = new Character(UserName, 150, 50, 5, 0);
                        break;
                    case 3:
                        //selectCharacter(UserName, 125, 75, 9);
                        Player[0] = new Character(UserName, 125 , 75, 7, 0);
                        break;
                }   
            
                Player[1] = new Character("Private Joey", 75, 20, 2, 0);
                Player[2] = new Character("Commander John", 100, 40, 4, 0);
                Player[3] = new Character("General Wes", 125, 60, 6, 0);
                Player[4] = new Character("King Vandergriff", 200, 75, 9, 0);
                //this section runs the actual game
                do {

                    startingPoint = F->rungame(startingPoint, Player);
                    
                    //breaks if character dies (0) or character beats the game (8)
                    if (startingPoint == 0)
                        break;
                    if (startingPoint == 8)
                        break;
                    
                
                    cout << "\nWould you like to continue? Yes(1) or No (2)\n";
                    
                    cin >> choice;
                    
                    //choice = I.checkInput(choice); 
                    cout << choice;
                }   while (choice !=2);
                //breaks if character dies (0) or character beats the game (8)
                if (startingPoint == 0){
                    cout << "Sorry you couldn't beat the game...see you next time, " << UserName << ". Your Save file will be deleted." << endl;
                    //clears file
                    outFile.open(fileName); 
                    outFile << ""; 
                    outFile.close();
                    break;
                }
                if (startingPoint == 8){
                    cout << "Congrats you beat the game!! see you next time, " << UserName << ". Your Save file will be deleted." << endl;
                    //clears file
                    outFile.open(fileName); 
                    outFile << ""; 
                    outFile.close();
                    break;
                }
            
                outFile.open(fileName, ios::app); //opens save text file

                outFile << *(Player[0]);

                //Save file template: name#numHP#numAP#numSP#numlevel#
                //Save file  example: Brandon Vandy#143#10#998#7#

                outFile << startingPoint << "#";
                outFile.close();

                inFile.close();
                break;
               
                
            case 2:
                choice = 1;

                while (!inFile.is_open()){
                    cout << "Which save file would you like to open? (Ex. File_Name.txt)\n";
                    cin >> fileName;
                    inFile.open(fileName);
                    if (inFile.is_open())
                        break;
                    cout << "\nNo file with that name exists. Try again? Yes(1) or No (2)\n";
                    choice = I->checkInput(choice);
                    if (choice != 1)
                        break;
                }
                if (choice != 1)
                        break;

                //reads in the starting point from the end of the file, without reading in unneed data 
                inFile.open(fileName);
                //this section loads the character from the textfile into the actual character info
                getline(inFile, UserName, '#');
                getline(inFile, grabberString, '#');
                c.setHealthPoints(stoi(grabberString));
                getline(inFile, grabberString, '#');
                c.setAttackStat(stoi(grabberString));
                getline(inFile, grabberString, '#');
                c.setSpeed(stoi(grabberString));
                getline(inFile, grabberString, '#'); 
                startingPoint =  stoi(grabberString);
                inFile.close();
                //this section runs the actual game, assuming it has been opened
                do {
                    startingPoint = F->rungame(startingPoint, Player);
                    //breaks if character dies (0) or character beats the game (8)
                    if (startingPoint == 0)
                        break;
                    if (startingPoint == 8)
                        break;
                    
                    cout << "\nWould you like to continue? Yes(1) or No (2)\n";
                    cin >> choice;
                    choice = I->checkInput(choice);
                }   while (choice == 1);
                //breaks if character dies (0) or character beats the game (8)
                if (startingPoint == 0){
                    cout << "Sorry you couldn't beat the game...see you next time, " << UserName << endl;
                    //clears file
                    outFile.open(fileName); 
                    outFile << ""; 
                    outFile.close();
                    break;
                }
                if (startingPoint == 8){
                    cout << "Congrats you beat the game!! see you next time, " << UserName << endl;
                    //clears file
                    outFile.open(fileName); 
                    outFile << ""; 
                    outFile.close();
                    break;
                }

                outFile.open(fileName, ios::app); //opens save text file

                outFile << *(Player[0]);

                //Save file template: name#numHP#numAP#numSP#numlevel#
                //Save file  example: Brandon Vandy#143#10#998#7#

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
                    choice = I->checkInput(choice);
                    if (choice != 1)
                        break;
                }
                if (!outFile.is_open())
                    break;
                
                outFile << ""; // should clear file

                outFile.close();
                break;
            default:
                choice = 4;
        }

    }while (choice == 4);
    
    cout << "\nThanks for playing...\n";
    cout << 
    R"( 
    _______     __    __  .__   __.    _______   _______    ______    .__    __.      _______      ___        .___   ___.  _______ 
    |       \\ |  |  |  | |  \\ |  |  /  _____| |   ____|  /  __  \\  |  \\ |  |     /  _____|    /   \\      |   \\/   | |   ____|
    |  .--.  | |  |  |  | |   \\|  | |  |  __   |  |__    |  |  |  |  |   \\|  |    |  |  __     /  ^  \\     |  \\  /  | |  |__   
    |  |  |  | |  |  |  | |  . `   | |  | |_ |  |   __|   |  |  |  |  |  . `   |    |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  
    |  '--'  | |  `--'  | |  |\\   | |  |__| |  |  |____  |  `--'  |  |  |\\   |    |  |__| |  /  _____  \\   |  |   |  | |  |____ 
    |_______/  \\______/  |__| \\__|  \\______| |_______| \\______/   |__| \\__|    \\______| /__/     \\__\\ |__|   |__| |_______|)" << endl;
    /*            
    delete [] Player;
    delete [] PrintC;
    delete [] game;
    */
    return 0;
}