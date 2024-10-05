#include "Character.h"
#include "Forest.h"
#include "Interactions.h"

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
        delete [] arrayOfItems;
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
        Forest *f;
        int num = (rand()%3)+1;
        switch(num){
            case 1:
                arrayOfItems[0] = f->getroomItem(2,0); 
                
                break;
            case 2:
                arrayOfItems[0] = f->getroomItem(2,1);
                
                break;
            case 3:
                arrayOfItems[0] = f->getroomItem(2,2);
                
                break;
        }    
        return arrayOfItems[0];
    }

    string Character::setArrayOfItems00()
    {
        Forest *f;
        arrayOfItems[0] = f->getroomItem(1,0);
        return arrayOfItems[0];
    }

    string Character::setArrayOfItems1()
    {
        Forest *f;
        arrayOfItems[1] = f->getroomItem(3,0);
        return arrayOfItems[1]; 
    }

    string Character::setArrayOfItems2()
    {
        Forest *f;
        int num = (rand()%3)+1;
        
        switch(num){

            case 1:
                arrayOfItems[2] = f->getroomItem(4,0);
                break;
            case 2:
                arrayOfItems[2] = f->getroomItem(4,1);
                break;
            case 3:
                arrayOfItems[2] = f->getroomItem(4,2); 
                break;
        }   
        return arrayOfItems[2];
    }

    string Character::setArrayOfItems22()
    {
        Forest *f;
        arrayOfItems[2] = f->getroomItem(5,0); 
        return arrayOfItems[2];
    }

   