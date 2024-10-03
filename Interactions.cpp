#include "Interactions.h"
#include "Character.h"

Interactions::Interactions(int d,int rh,string AN,string RN)
{
    damage = d;
    remaninghealth = rh;
    AttckerName = AN;
    ReciverName = RN;
}
void Interactions::makebattlelog()
{   int i;
    battlelog = new string[i];

}

string Interactions::getDamage() const
{   string i ;
    i = damage;
    return i;
}
string Interactions::getRH() const
{   string i;
    i = remaninghealth;
    return i;
}
string Interactions::getAN() const
{
    return AttckerName;
}
string Interactions::getRN() const
{
    return ReciverName;
}
string Interactions::PH(Interactions i)
{   string strm;
    strm = i.getAN(), " hit ", i.getRN(), " for ", i.getDamage(), ", ", i.getRN(), " has ", i.getRH(), " left.";
    return strm;


}
string Interactions::log(int s,Interactions *b)
{   battlelog = new string[s];
    for (int i = 0; i < s; i++)
    {
        battlelog[i] = b->PH(b[i]);
    }
    


}


int Interactions::damagedelt(int attack)
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

int Interactions::characterremaninghealth(int damage,int health)
{   
    int HPleft;
    HPleft = health - damage;
    return HPleft;
}

void Interactions::fight(Character Unit[], int BadGuy)
{   int char1speed, Enemyspeed;
    int char1attack, Enemyattack;
    int char1hp, Enemyhp;
    string char1name, Enemyname;
    Character Player,Enemy;
    Player = Unit[0];
    Enemy = Unit[BadGuy];
    char1name = Player.getName();
    char1attack = Player.getAttackStat();
    char1hp = Player.getHealthPoints();
    char1speed = Player.getSpeed();
    Enemyname = Enemy.getName();
    Enemyattack = Enemy.getAttackStat();
    Enemyhp = Enemy.getHealthPoints();
    Enemyspeed = Enemy.getSpeed();
}

int Interactions::runGame(int startingPoint, Character Unit[])
{
    int Enemy1 = 1 , Enemy2 = 2, Enemy3 = 3;
    switch (startingPoint)
    {
        case 1: //where is case 1, 3, and 5?? - chris
            
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

int Interactions::damagedelt(int attack)
{   
    int damagemulti,damage;
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