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


class Forest 
{
    private:
        string rooms[7] = {"Start Room", "Room 1", "Room 2", "Room 3", "Room 4", "Room 5", "Fight Room"};
        string currentRoom;
        string*** roomItems;
        bool gameOver;

    public:
        Forest() : currentRoom("Start Room"), gameOver(false) 
        {
            roomItems = new string**[4];

            for (int i = 0; i < 7; ++i) 
            {
                roomItems[i] = new string*[2];
            }

            roomItems[1][0] = new string("Map");
            roomItems[1][1] = new string("Key");

            roomItems[2][0] = new string("Sword");
            roomItems[2][1] = new string("Shield");

            roomItems[4][0] = new string("Healing Potion");
            roomItems[4][1] = new string("Armor");

            roomItems[5][0] = new string("Bow");
            roomItems[5][1] = new string("Arrows");
        }

        ~Forest() 
        {
            for (int i = 0; i < 7; ++i) 
            {
                for (int j = 0; j < 2; ++j)
                {
                    delete roomItems[i][j];
                }
                delete[] roomItems[i];
            }  
            delete[] roomItems; 
        }

        void displayCurrentRoom() 
        {
            cout << "\nYou are currently in " << currentRoom << endl;
            displayRoomItems();
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
        void displayRoomItems() 
        {
            // Find the current room index
            int roomIndex = getRoomIndex(currentRoom);
            if (roomIndex != -1) 
            {
                cout << "Items in this room: " << *roomItems[roomIndex][0] << ", " << *roomItems[roomIndex][1] << endl;
            }
        }

        int getRoomIndex(const string& room) 
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

        void handleStartLine() 
        {
            int input;
        ask1:
            displayCurrentRoom();
            cout << "What would you like to do?" << endl;
            cout << "1: Go to Room 1" << endl;
            cout << "2: Go to Room 2" << endl;
            cin >> input;

            if (input != 1 && input != 2) goto ask1;
            currentRoom = rooms[input];
        }

        void handleRoom1and2() 
        {
            int input;
        ask2:
            displayCurrentRoom();
            cout << "What would you like to do?" << endl;
            cout << "3: Go to Room 3" << endl;
            cin >> input;

            if (input != 3) goto ask2;
            currentRoom = rooms[input];
        }

        void handleRoom3() 
        {
            int input;
        ask3:
            displayCurrentRoom();
            cout << "What would you like to do?" << endl;
            cout << "4: Go to Room 4" << endl;
            cout << "5: Go to Room 5" << endl;
            cin >> input;

            if (input != 4 && input != 5) goto ask3;
            currentRoom = rooms[input];
        }

        void handleRoom4and5() 
        {
            int input;
        ask4:
            displayCurrentRoom();
            cout << "Enter 6 to go to the Boss Fight" << endl;
            cin >> input;

            if (input != 6) goto ask4;
            currentRoom = "Fight Room";
        }

        void handleFightRoom() 
        {
            displayCurrentRoom();
            cout << "You have reached the end of the game!" << endl;
            gameOver = true;
        }
};

class Character
{

	private: 
                
        string name;
        int healthPoints;
        int attackStat;
        int speed;
        string* arrayOfitems;
        int numItems;
        
    public:
    Character();
    Character(string n,int hp,int as,int s);
    ~Character();

    //overloaded operator from song.h example.
    friend ostream &operator << (ostream &strm, Character &c)
		{
			strm << c.name << "#" << c.healthPoints << "#" << c.attackStat << "#" << c.speed << "#" <<c.numItems;
			return strm;
		}

    Character(string n, int hp, int as, int s) 
    {
        name = n;
        healthPoints = hp;
        attackStat = as;
        speed = s;
    }

    string getName() const 
    {
        return name;
    }
    void setName(string n)
    {
        name = n;
    }

    int getHealthPoints() const
    {
        return healthPoints;
    }
    void setHealthPoints(double hp)
    {
        healthPoints = hp;
    }

    int getAttackStat() const
    {
        return attackStat;
    }
    void setAttackStat(double as)
    {
        attackStat = as;
    }

    int getSpeed() const
    {
        return speed;
    }
    void setSpeed(int s)
    {
        speed = s;
    }

    void setArrayOfItems0(string numItems, int i)
    {   Character IP;
        IP.arrayOfitems[0] = "computer of doom";    
    }

    void setArrayOfItems1(string numItems, int i)
    {
        Character IP;
        IP.arrayOfitems[1] = "Chick-Fil-A Sandwhich";
    }

    void setArrayOfItems2(string numItems, int i)
    {
        Character IP;
        IP.arrayOfitems[2] = "Coder's shoes";
    }
    //string Character::setName(string n);
    /*{
        name = n;
    };//put Character:: in character.cpp*/
    
   // Character selectCharacter(string name, double healthPoints, double attackStat, int speed);
    void printCharacters(Character* selectCharacter);
   
};

Character setNumItems(string arrayOfitems[])
{
    int numItems = 3;
     arrayOfitems = new string[numItems];
}

void Character::printCharacters(Character* selectCharacter)
{
    cout << "Character Name:    " << selectCharacter->name << endl;
    cout << "Health Points:   " << selectCharacter->healthPoints << endl;
    cout << "Hit Points:  " << selectCharacter->attackStat << endl;
    cout << "Speed :    " << selectCharacter->speed << endl;
}
/*class Interactions
{
     private:
        int damage, remaninghealth;
        string* battlelog;
    public:
        Interactions();
        Interactions(int,int,string,string);
        ~Interactions();
        int damagedelt(int);
        int characterremaninghealth(int,int);
        string log(int,int,string,string);
        void savelogtofile(fstream,string);
         during a fight add each cout of x did x damage to x and x has x hp left
        to the string array battlelog then after the fight call a function that
        is a for loop that prints every element of the array into a txt file.
}; */



int damagedelt(int attack)
{   int damagemulti,damage;
    damagemulti = (rand() % 3) + 1;
    if (damagemulti == 1)
    {   
        damage = attack * 0.75;
    }
    if (damagemulti == 2)
    {   
        damage = attack;
    }
    if (damagemulti == 3)
    {   
        damage = attack * 1.25;
    }
    return damage;
}
int characterremaninghealth(int damage,int health)
{   
    int HPleft;
    HPleft = health - damage;
    return HPleft;
}
void fight(Character Unit[], int BadGuy)
{   int Playerspeed, Enemyspeed;
    int Playerattack, Enemyattack;
    int Playerhp, Enemyhp;
    int ouch,logcounter=0;
    string Playername, Enemyname, log;
    Character Player,Enemy;
    Interactions **battle;
    battle = new Interactions*[logcounter];
    Player = Unit[0];
    Enemy = Unit[BadGuy];
    Playername = Player.getName();
    Playerattack = Player.getAttackStat();
    Playerhp = Player.getHealthPoints();
    Playerspeed = Player.getSpeed();
    Enemyname = Enemy.getName();
    Enemyattack = Enemy.getAttackStat();
    Enemyhp = Enemy.getHealthPoints();
    Enemyspeed = Enemy.getSpeed();

    if(Playerspeed > Enemyspeed)
    {   
        cout << endl << Playername << " outsped " << Enemyname << " and was able to attack first." << endl; 
        
        do
        {
            ouch = damagedelt(Playerattack);
            Enemyhp = characterremaninghealth(ouch,Enemyhp);
            battle[logcounter]= new Interactions(ouch,Enemyhp,Playername,Enemyname);
            logcounter++;
            cout << Playername << " inflicted " << ouch << " damage to " << Enemyname << ", " << Enemyname << " has " << Enemyhp << " hp left." << endl;
            if (Enemyhp <=0)
            {
                cout << Playername << " absolutly wreked " << Enemyname << "freakin ez sauce gg." << endl;
                break;
            }
            ouch = damagedelt(Enemyattack);
            Playerhp = characterremaninghealth(ouch,Playerhp);
            battle[logcounter]= new Interactions(ouch,Playerhp,Playername,Enemyname);
            logcounter++;
            cout << Enemyhp << " inflicted " << ouch << " damage to " << Playername << ", " << Playername << " has " << Playerhp << " hp left." << endl;
            if(Playerhp <= 0)
            {
                cout << Playername << " got freakin merked bro, by " << Enemyname << " get good bro." << endl;
                break;
            }
            //insert interacti0ns pointer log to save the battle in a string log
        } while (Playerhp > 0 && Enemyhp > 0);
    }


    
    if(Enemyspeed > Playerspeed) 
    {
        cout << endl << Enemyname << " outsped " << Playername << " and was able to attack first." << endl; 
        do
        {
            ouch = damagedelt(Enemyattack);
            Playerhp = characterremaninghealth(ouch,Playerhp);
            battle[logcounter] = new Interactions(ouch,Playerhp,Playername,Enemyname);
            logcounter++;
            cout << Enemyname << " inflicted " << ouch << " damage to " << Playername << ", " << Playername << " has " << Playerhp << " hp left." << endl;
            if(Playerhp <= 0)
            {
                cout << Playername << " got freakin merked bro, by " << Enemyname << " get good bro." << endl;
                break;
            }
            ouch = damagedelt(Playerattack);
            Enemyhp = characterremaninghealth(ouch,Enemyhp);
            battle[logcounter] = new Interactions(ouch,Enemyhp,Playername,Enemyname);
            logcounter++;
            cout << Playername << " inflicted " << ouch << " damage to " << Enemyname << ", " << Enemyname << " has " << Enemyhp << " hp left." << endl;
            if (Enemyhp <=0)
            {
                cout << Playername << " absolutly wreked " << Enemyname << "freakin ez sauce gg." << endl;
                break;
            }
            //insert interacti0ns pointer log to save the battle in a string log 
        } while (Playerhp > 0 && Enemyhp > 0);
        
       
    }
    







}



int runGame(int startingPoint, Character Unit[]){
    int Enemy1 = 1 , Enemy2 = 2, Enemy3 = 3;
    switch (startingPoint)
    {
        case 1: 
            
            break;
        case 2: 
            Unit[1];
            fight(Unit,Enemy1);
            break;
        case 3: 
            
            break;
        case 4: 
            Unit[2];
            break;
        case 5: 
             
            break;
        case 6: 
             Unit[3];
            break;
        case 7: 
             Unit[4];
            break;
    }

    return startingPoint;
    }


int getValidateInput(){
	int num;
	
	
		while(!(cin >> num))
		{
			cout << "Please enter a valid number" << endl;
			cin.clear(); //clears all stream bits (good, bad, eof, fail)
			cin.ignore(10000, '\n'); //removes up to 10000 characters from buffer until a newline is removed
			cout << "\nEnter a number: ";
		}
	
		
	return num;
}

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