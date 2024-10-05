#include "Forest.h"

Forest::Forest()
{  
    int i;
    roomItems = new string*[numrooms];
    roomItems[numrooms] = new string[numItems];
    
    roomItems[1][0]= "Great Sword of DOOM";
    roomItems[2][0]= "Sword of lame";
    roomItems[2][1]= "Mid Sword of mid";
    roomItems[2][2]= "Great Sword of DOOM";
    roomItems[3][0]= "Deluxe Chick-Fil-A Sandwhich";
    roomItems[4][0]= "Walmart slides de Coder";
    roomItems[4][1]= "Adidas slides de Coder";
    roomItems[4][2]= "Gucci slides de Coder";
    roomItems[5][0]= "Gucci slides de Coder";
 
}

Forest::~Forest() 
{
    delete [] roomItems;
}

string Forest::getroomItem(int i,int j)
{
    return roomItems[i][j];
}



int Forest::handleStartLine() 
{
    int userchoice;
    do
    {   
        cout << "You see two paths before you, one left the other right. Unknown what lies beyond but you must choose one." << endl;
        cout << "1: to go left and get jeffed." << endl;
        cout << "2: to go right and prove your might." << endl;
        cin >> userchoice;
        if(userchoice != 1 && userchoice != 2)
            cout <<"\nThere is no secret third option, the only choices are the ones in front of you." << endl;
    }
    while (userchoice != 1 && userchoice != 2);
   
    return userchoice+1;
}


int Forest::handleRoom3() 
{
    int userchoice;
    do
    {
        cout << "You see two paths before you, one left the other right. Unknown what lies beyond but you must choose one." << endl;
        cout << "You can't be sure if you are going in circles or not." << endl;
        cout << "1: go left and commit a theft!" << endl;
        cout << "2: go right and become a Knight!" << endl;
        cin >> userchoice;
        if(userchoice != 1 && userchoice != 2)
            cout <<"\nWhat are you doing. You should have learned from the first time." << endl;
    }
    while (userchoice != 1 && userchoice != 2);
  
    return userchoice+4;
}

int Forest::runGame(int startingPoint, Character Unit[])
{   bool Fightoutcome = false;
    int roomchoice;
    int Enemy1 = 1 , Enemy2 = 2, Enemy3 = 3,Boss = 4;
    string itemName[3];
    Character c;
    Forest f;
    Interactions i;

    switch (startingPoint)
    {
        case 1: 
            cin.ignore();
            roomchoice = f.handleStartLine();            
            
            break;
        case 2: 
            Fightoutcome = i.fight(Unit,Enemy1);
            if (Fightoutcome = true)
            {
                itemName[0] = c.setArrayOfItems00();
                cout << "Your enemy drops the " << itemName[0];
                c.setAttackStat(c.getAttackStat()+30);
                cout << "\n you are given a 30 point attact stat boost!\n";
                roomchoice = 4;
            }
            if (Fightoutcome = false)
            {
                roomchoice = 0;
            }
            
            break;
        case 3: 
            itemName[0] = c.setArrayOfItems0();
            cout << "You enter a room with nothing but a chest\n\nYou open the chest to find The " << itemName[0];
            if (itemName[0]==roomItems[2][0]){
                c.setAttackStat(c.getAttackStat()+10);
                cout << "\n you are given a 10 point attact stat boost!\n";
            }
            else if (itemName[0]==roomItems[2][1]){
                c.setAttackStat(c.getAttackStat()+20);
                cout << "\n you are given a 20 point attact stat boost!\n";
            }
            else {
                c.setAttackStat(c.getAttackStat()+30);
                cout << "\n you are given a 30 point attact stat boost!\n";
            }
            roomchoice = 5;
            break;
        case 4: 
            Fightoutcome = i.fight(Unit,Enemy2);
            if (Fightoutcome = true)
            {
                itemName[1] = c.setArrayOfItems1();
                cout << "Your enemy drops the " << itemName[1];
                c.setHealthPoints(c.getHealthPoints()+100);
                cout << "\n you recover 100 HP with the lords chiken!\n";
                roomchoice = f.handleRoom3();
            }
            if (Fightoutcome = false)
            {
                roomchoice = 0;
            }
            break;
        case 5: 

            itemName[2] = c.setArrayOfItems2();
            cout << "You enter a room with nothing but a chest\n\nYou open the chest to find The " << itemName[2];
            if (itemName[2]==roomItems[4][0]){
                c.setSpeed(c.getSpeed()+1);
                cout << "\n you are given a 1 point speed stat boost!\n";
            }
            else if (itemName[2]==roomItems[4][1]){
                c.setSpeed(c.getSpeed()+2);
                cout << "\n you are given a 3 point speed stat boost!\n";
            }
            else {
                c.setSpeed(c.getSpeed()+3);
                cout << "\n you are given a 3 point speed stat boost!\n";
            }
            roomchoice = 7;
            break;
        case 6: 
            Fightoutcome = i.fight(Unit,Enemy3);
            if (Fightoutcome = true)
            {
            itemName[2] = c.setArrayOfItems22();
            cout << "Your enemy drops the " << itemName[2];
            c.setSpeed(c.getSpeed()+5);
            cout << "\n you are given a 5 point speed stat boost!\n";
 
                roomchoice = 7;
            }
            if (Fightoutcome = false)
            {
                roomchoice = 0;
            }
       
            break;
        case 7: 
            Fightoutcome = i.fight(Unit,Boss);
            if (Fightoutcome = true)
            {
                roomchoice = 8;
            }
            if (Fightoutcome = false)
            {
                roomchoice = 0;
            }

            break;
    }

    return roomchoice;
}

