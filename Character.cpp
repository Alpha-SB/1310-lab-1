#include "Character.h"

   Character::Character(string n, int hp, int as, int s)
    {
        name = n;
        healthPoints = hp;
        attackStat = as;
        speed = s;
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
		strm << c.name << "#" << c.healthPoints << "#" << c.attackStat << "#" << c.speed << "#";
		return strm;
	}

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

    void Character::setArrayOfItems0(string numItems, int i)
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

   