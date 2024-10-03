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
} 
   Character::Character(string n, int hp, int as, int s)
    {
        name = "";             
        healthPoints = 0;      
        attackStat = 0;        
        speed = 0;             
        numItems = 0;          
    }    

    Character::~Character()
    {
        
    }

    void Character::CreateCharacter(string n, int hp, int as, int s, int i)
    {
        name = n;
        healthPoints = hp;
        attackStat = as;
        speed = s;
        numItems = i;
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

<<<<<<< Updated upstream
    void Character::setArrayOfItems0(string numItems, int i)
    {   //Character IP;
        arrayOfItems[0] = "Computer of Doom";    
=======
    string Character::setArrayOfItems0()
    {   
        int num = (rand()%3)+1;
        
        switch(num){

            case 1:
                arrayOfItems[0] = "Computer of lame"; 
                return arrayOfItems[0];
            case 2:
                arrayOfItems[0] = "Mid Computer of mid";
                return arrayOfItems[0];
            case 3:
                arrayOfItems[0] = "Great Computer of doom";
                return arrayOfItems[0];
        }    
>>>>>>> Stashed changes
    }

    string Character::setArrayOfItems1()
    {
        int num = (rand()%3)+1;
        
        switch(num){

            case 1:
                arrayOfItems[1] = "Deluxe Chick-Fil-A Sandwhich"; 
                return arrayOfItems[0];
            case 2:
                arrayOfItems[1] = "Chick-Fil-A Sandwhich";
                return arrayOfItems[0];
            case 3:
                arrayOfItems[1] = "Coder's shoes";
                return arrayOfItems[0];
        }   
    }

    string Character::setArrayOfItems2()
    {
<<<<<<< Updated upstream
        //Character IP;
        arrayOfItems[2] = "Coder's Shoes";
=======
        
        int num = (rand()%3)+1;
        
        switch(num){

            case 1:
                arrayOfItems[2] = "computer of doom"; 
                return arrayOfItems[0];
            case 2:
                arrayOfItems[2] = "Chick-Fil-A Sandwhich";
                return arrayOfItems[0];
            case 3:
                arrayOfItems[2] = "Coder's shoes";
                return arrayOfItems[0];
        }   
>>>>>>> Stashed changes
    }

   