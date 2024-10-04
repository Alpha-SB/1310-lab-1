#include "Interactions.h"
#include "Character.h"

Interactions::Interactions(){
    damage = 0;
    remaninghealth = 1;
    AttckerName = "Default";
    ReciverName = "Default";
}

Interactions::Interactions(int d,int rh,string AN,string RN)
{
    damage = d;
    remaninghealth = rh;
    AttckerName = AN;
    ReciverName = RN;
}

Interactions::~Interactions(){

}

void Interactions::makebattlelog()
{   
    int i;
    battlelog = new string[i];
}

string Interactions::getDamage() const
{   
    string i ;
    i = damage;
    return i;
}
string Interactions::getRH() const
{   
    string i;
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
string Interactions::savetolog(Interactions i)
{   
    string strm;
    strm = i.getAN(), " hit ", i.getRN(), " for ", i.getDamage(), ", ", i.getRN(), " has ", i.getRH(), " left.";
    return strm;
}

string Interactions::log(int s,Interactions *b)
{   
    battlelog = new string[s];
    for (int i = 0; i < s; i++)
    {
        battlelog[i] = b->savetolog(b[i]);
    }
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

int Interactions::characterremaninghealth(int damage,int health)
{   
    int HPleft;
    HPleft = health - damage;
    return HPleft;
}

void Interactions::fight(Character Unit[], int BadGuy)
{   int Playerspeed, Enemyspeed;
    int Playerattack, Enemyattack;
    int Playerhp, Enemyhp;
    int ouch,logcounter=0;
    string Playername, Enemyname, log;
    Character Player,Enemy;
    Interactions **battle;
    Interactions Lholder;
    battle = new Interactions*[logcounter];
    Player = Unit[0];
    Enemy = Unit[BadGuy];
    Playername = Player.getName();
    Playerattack = Player.getAttackStat();
    Playerhp = Player.getHealthPoints();
    Playerspeed = Player.getSpeed();
    Enemyname = Enemy.getName();
    Enemyattack = Enemy.getAttackStat();
    Enemyhp = Enemy.getHealthPoints();
    Enemyspeed = Enemy.getSpeed();
     if(Playerspeed > Enemyspeed)
    {   
        cout << endl << Playername << " outsped " << Enemyname << " and was able to attack first." << endl; 
        
        do
        {
            ouch = damagedelt(Playerattack);
            Enemyhp = characterremaninghealth(ouch,Enemyhp);
            battle[logcounter]= new Interactions(ouch,Enemyhp,Playername,Enemyname);
            logcounter++;
            cout << Playername << " inflicted " << ouch << " damage to " << Enemyname << ", " << Enemyname << " has " << Enemyhp << " hp left." << endl;
            if (Enemyhp <=0)
            {
                cout << Playername << " absolutly wreked " << Enemyname << "freakin ez sauce gg." << endl;
                Lholder.log(logcounter,*battle);
                break;
            }
            ouch = damagedelt(Enemyattack);
            Playerhp = characterremaninghealth(ouch,Playerhp);
            battle[logcounter]= new Interactions(ouch,Playerhp,Playername,Enemyname);
            logcounter++;
            cout << Enemyhp << " inflicted " << ouch << " damage to " << Playername << ", " << Playername << " has " << Playerhp << " hp left." << endl;
            if(Playerhp <= 0)
            {
                cout << Playername << " got freakin merked bro, by " << Enemyname << " get good bro." << endl;
                Lholder.log(logcounter,*battle);
                break;
            }
            //insert interacti0ns pointer log to save the battle in a string log
        } while (Playerhp > 0 && Enemyhp > 0);
    }


    
    if(Enemyspeed > Playerspeed) 
    {
        cout << endl << Enemyname << " outsped " << Playername << " and was able to attack first." << endl; 
        do
        {
            ouch = damagedelt(Enemyattack);
            Playerhp = characterremaninghealth(ouch,Playerhp);
            battle[logcounter] = new Interactions(ouch,Playerhp,Playername,Enemyname);
            logcounter++;
            cout << Enemyname << " inflicted " << ouch << " damage to " << Playername << ", " << Playername << " has " << Playerhp << " hp left." << endl;
            if(Playerhp <= 0)
            {
                cout << Playername << " got freakin merked bro, by " << Enemyname << " get good bro." << endl;
                Lholder.log(logcounter,*battle);
                break;
            }
            ouch = damagedelt(Playerattack);
            Enemyhp = characterremaninghealth(ouch,Enemyhp);
            battle[logcounter] = new Interactions(ouch,Enemyhp,Playername,Enemyname);
            logcounter++;
            cout << Playername << " inflicted " << ouch << " damage to " << Enemyname << ", " << Enemyname << " has " << Enemyhp << " hp left." << endl;
            if (Enemyhp <=0)
            {
                cout << Playername << " absolutly wreked " << Enemyname << "freakin ez sauce gg." << endl;
                Lholder.log(logcounter,*battle);
                break;
            }
            //insert interacti0ns pointer log to save the battle in a string log 
        } while (Playerhp > 0 && Enemyhp > 0);
    }
}

int Interactions::runGame(int startingPoint, Character Unit[])
{

    int Enemy1 = 1 , Enemy2 = 2, Enemy3 = 3;
    string itemName;
    Character c;
    
    switch (startingPoint)
    {
        case 1: 

            itemName = c.setArrayOfItems0();
            cout << "You enter a room with nothing but a chest\n\nYou open the chest to find The " << itemName;
            if (itemName[0]=='S'){
                c.setAttackStat(c.getAttackStat()+10);
                cout << "\n you are given a 10 point attact stat boost!\n";
            }
            else if (itemName[0]=='M'){
                c.setAttackStat(c.getAttackStat()+20);
                cout << "\n you are given a 20 point attact stat boost!\n";
            }
            else {
                c.setAttackStat(c.getAttackStat()+30);
                cout << "\n you are given a 30 point attact stat boost!\n";
            }
            return 3;
        case 2: 
            Unit[1];
            fight(Unit,Enemy1);
            itemName = c.setArrayOfItems0();
            cout << "Your enemy drops the " << itemName;
            if (itemName[0]=='S'){
                c.setAttackStat(c.getAttackStat()+10);
                cout << "\n you are given a 10 point attact stat boost!\n";
            }
            else if (itemName[0]=='M'){
                c.setAttackStat(c.getAttackStat()+20);
                cout << "\n you are given a 20 point attact stat boost!\n";
            }
            else {
                c.setAttackStat(c.getAttackStat()+30);
                cout << "\n you are given a 30 point attact stat boost!\n";
            }
            return 3;
        case 3: 
            itemName = c.setArrayOfItems1();
            cout << "You enter a room with nothing but a chest\n\nYou open the chest to find The " << itemName;
            if (itemName[0]=='W'){
                c.setSpeed(c.getSpeed()+10);
                cout << "\n you are given a 1 point speed stat boost!\n";
            }
            else if (itemName[0]=='N'){
                c.setSpeed(c.getSpeed()+20);
                cout << "\n you are given a 2 point speed stat boost!\n";
            }
            else {
                c.setSpeed(c.getSpeed()+30);
                cout << "\n you are given a 3 point speed stat boost!\n";
            }
            return 5;
            break;
        case 4: 

            Unit[2];
            itemName = c.setArrayOfItems1();
            cout << "Your enemy drops the " << itemName;
            if (itemName[0]=='W'){
                c.setSpeed(c.getSpeed()+1);
                cout << "\n you are given a 1 point speed stat boost!\n";
            }
            else if (itemName[0]=='N'){
                c.setSpeed(c.getSpeed()+2);
                cout << "\n you are given a 2 point speed stat boost!\n";
            }
            else {
                c.setSpeed(c.getSpeed()+3);
                cout << "\n you are given a 3 point speed stat boost!\n";
            }
            return 5;
            break;
        case 5: 

            itemName = c.setArrayOfItems2();
            cout << "You enter a room with nothing but a chest\n\nYou open the chest to find The " << itemName;
            if (itemName[0]=='H'){
                c.setHealthPoints(c.getHealthPoints()+25);
                cout << "\n you are given a 25 point speed stat boost!\n";
            }
            else if (itemName[0]=='C'){
                c.setHealthPoints(c.getHealthPoints()+50);
                cout << "\n you are given a 50 point speed stat boost!\n";
            }
            else {
                c.setHealthPoints(c.getHealthPoints()+75);
                cout << "\n you are given a 75 point speed stat boost!\n";
            }
            return 7;
            break;
        case 6: 

            Unit[3];
            itemName = c.setArrayOfItems2();
            cout << "You enemy drops the " << itemName;
            if (itemName[0]=='H'){
                c.setHealthPoints(c.getHealthPoints()+25);
                cout << "\n you are given a 25 point speed stat boost!\n";
            }
            else if (itemName[0]=='C'){
                c.setHealthPoints(c.getHealthPoints()+50);
                cout << "\n you are given a 50 point speed stat boost!\n";
            }
            else {
                c.setHealthPoints(c.getHealthPoints()+75);
                cout << "\n you are given a 75 point speed stat boost!\n";
            }
            return 7;
            break;
        case 7: 

            Unit[4];
            return 8;
            break;
    }

    return startingPoint;
}
