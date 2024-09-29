#include<Interactions.h>

int damage(int attack)
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
int remaininghealth(int damage,int health)
{   
    int HPleft;
    HPleft = health - damage;
    return HPleft;
}
void fight(Character[1],Character[2])
{


    
}
