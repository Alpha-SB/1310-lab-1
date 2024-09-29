#include <iostream>
#ifndef Character_H
#define Character_H

using namespace std;

class Character
{
    private:
    string name;
    int healthPoints;
    int attackStat;
    int speed;
    string* arrayOfItems;
    int numItems;

    public:
     Character(string, int, int, int);

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

    int Character::getSpeed() const
    {
        return speed;
    }
    void Character::setSpeed(int s)
    {
        speed = s;
    }

    friend ostream &operator << (ostream &strm, Character &c)
	{
		strm << c.name << "#" << c.healthPoints << "#" << c.attackStat << "#" << c.speed << "#";
		return strm;
	}

};

#endif