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

    void Character::setArrayOfItems0(string numItems, int i)
    {   //Character IP;
        arrayOfItems[0] = "Computer of Doom";    
    }

    void Character::setArrayOfItems1(string numItems, int i)
    {
        //Character IP;
        arrayOfItems[1] = "Chick-Fil-A Sandwhich";//read it from a file, alloacte read back to a file
    }

    void Character::setArrayOfItems2(string numItems, int i)
    {
        //Character IP;
        arrayOfItems[2] = "Coder's Shoes";
    }

   