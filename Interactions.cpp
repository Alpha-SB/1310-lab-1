#include"Interactions.h"

Interactions::Interactions(int d,int rh)
{   
    damage = d;
    remaninghealth = rh;
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
