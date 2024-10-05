#include "Character.h"

#include<iomanip>

using namespace std;


   Character::Character() 
   {
    name = "";             
    healthPoints = 0;      
    attackStat = 0;        
    speed = 0;             
    numItems = 0;    
    arrayOfItems = new string[3];      
    } 

    Character::Character(string n, int hp, int as, int s, int i)
    {
        name = n;
        healthPoints = hp;
        attackStat = as;
        speed = s;
        numItems = i;   
        arrayOfItems = new string[3];       
    }    

    Character::~Character()
    {
        
    }

   
    
    string Character::getName() const 
    {
        return name;
    }

    void Character::setName(string n)
    {
        name = n;
    }

    int Character::getHealthPoints() const
    {
        return healthPoints;
    }

    void Character::setHealthPoints(int hp)
    {
        healthPoints = hp;
    }

    int Character::getAttackStat() const
    {
        return attackStat;
    }

    void Character::setAttackStat(int as)
    {
        attackStat = as;
    }

    int Character::getSpeed() const
    {
        return speed;
    }

    void Character::setSpeed(int s)
    {
        speed = s;
    }

    ostream& operator<<(ostream &strm, Character &c)
	{
		strm << c.name << "#" << c.healthPoints << "#" << c.attackStat << "#" << c.speed << "#" << c.numItems << "#" << c.arrayOfItems << "#";//Delimiter?
		return strm;
	}

    void Character::setNumItems(string* arrayOfitems)
    {
        //cout << "\nSET NUM ITEMS IS CALLED!!!\n";
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

    string Character::setArrayOfItems0()
    {   

        int num = (rand()%3)+1;
        switch(num){
            case 1:
                arrayOfItems[0] = "Sword of lame"; 
                return arrayOfItems[0];
                break;
            case 2:
                arrayOfItems[0] = "Mid Sword of mid";
                return arrayOfItems[0];
                break;
            case 3:
                arrayOfItems[0] = "Great Sword of DOOM";
                return arrayOfItems[0];
                break;
        }    
    }

    string Character::setArrayOfItems00()
    {
        arrayOfItems[0] = "Great Sword of DOOM";
        return arrayOfItems[0];

    }

    string Character::setArrayOfItems1()
    {
                arrayOfItems[1] = "Deluxe Chick-Fil-A Sandwhich";
                return arrayOfItems[1]; 
    }

    string Character::setArrayOfItems2()
    {
        
        int num = (rand()%3)+1;
        
        switch(num){

            case 1:
                arrayOfItems[2] = "Walmart slides de Coder";
                return arrayOfItems[2];
            case 2:
                arrayOfItems[2] = "Adidas slides de Coder";
                return arrayOfItems[2];
            case 3:
                arrayOfItems[2] = "Gucci slides de Coder"; 
                return arrayOfItems[2];
        }   
    }

    string Character::setArrayOfItems22()
    {
        arrayOfItems[2] = "Gucci slides de Coder"; 
        return arrayOfItems[2];

    }

   