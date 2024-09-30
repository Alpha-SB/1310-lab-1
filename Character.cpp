#include "Character.h"

   Character(string n, int hp, int as, int s)
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

   