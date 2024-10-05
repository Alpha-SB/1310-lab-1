#include "Interactions.h"
#include "Character.h"
#include "Forest.h"

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

Interactions::~Interactions()
{
    delete [] battlelog;
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

bool Interactions::fight(Character Unit[], int BadGuy)
{   int Playerspeed, Enemyspeed, Playerattack, Enemyattack, Playerhp, Enemyhp, ouch, logcounter=0;
    bool WinLose = false;
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
                WinLose = true;
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
                WinLose = true;
                break;
            }
            //insert interactions pointer log to save the battle in a string log 
        } while (Playerhp > 0 && Enemyhp > 0);
    }
    return WinLose
}

int Interactions::runGame(int startingPoint, Character Unit[])
{   bool Fightoutcome = false;
    int roomchoice;
    int Enemy1 = 1 , Enemy2 = 2, Enemy3 = 3,Boss = 4;
    string itemName;
    Character c;
    Forest f;
    Interactions i;

    switch (startingPoint)
    {
        case 1: 
            roomchoice = f.handleStartLine();            
            return roomchoice+1;
        case 2: 
            Fightoutcome = fight(Unit,Enemy1);
            if (Fightoutcome = true)
            {
                itemName = c.setArrayOfItems00();
                cout << "Your enemy drops the " << itemName;
                c.setAttackStat(c.getAttackStat()+30);
                cout << "\n you are given a 30 point attact stat boost!\n";
                roomchoice = 4;
            }
            if (Fightoutcome = false)
            {
                roomchoice = 0;
            }
            return roomchoice;
        case 3: 
            itemName = c.setArrayOfItems0();
            cout << "You enter a room with nothing but a chest\n\nYou open the chest to find The " << itemName;
            if (itemName[0]=='Walmart slides de Coder'){
                c.setAttackStat(c.getAttackStat()+10);
                cout << "\n you are given a 10 point attact stat boost!\n";
            }
            else if (itemName[0]=='Nikes de Coder'){
                c.setAttackStat(c.getAttackStat()+20);
                cout << "\n you are given a 20 point attact stat boost!\n";
            }
            else {
                c.setAttackStat(c.getAttackStat()+30);
                cout << "\n you are given a 30 point attact stat boost!\n";
            }
            return 5;
            break;
        case 4: 
            Fightoutcome = fight(Unit,Enemy2);
            if (Fightoutcome = true)
            {
                itemName = c.setArrayOfItems1();
                cout << "Your enemy drops the " << itemName;
                c.setHealthPoints(c.getHealthPoints()+100);
                cout << "\n you recover 100 HP with the lords chiken!\n";
                roomchoice = f.handleRoom3();
            }
            if (Fightoutcome = false)
            {
                roomchoice = 0;
            }
            return roomchoice;
        case 5: 

            itemName = c.setArrayOfItems2();
            cout << "You enter a room with nothing but a chest\n\nYou open the chest to find The " << itemName;
            if (itemName[0]=='Walmart slides de Coder'){
                c.setSpeed(c.getSpeed()+1);
                cout << "\n you are given a 1 point speed stat boost!\n";
            }
            else if (itemName[0]=='Nikes de Coder'){
                c.setSpeed(c.getSpeed()+2);
                cout << "\n you are given a 3 point speed stat boost!\n";
            }
            else {
                c.setSpeed(c.getSpeed()+3);
                cout << "\n you are given a 3 point speed stat boost!\n";
            }
            return 7;
            break;
        case 6: 
            Fightoutcome = fight(Unit,Enemy3);
            if (Fightoutcome = true)
            {
            itemName = c.setArrayOfItems22();
            cout << "Your enemy drops the " << itemName;
            c.setSpeed(c.getSpeed()+5);
            cout << "\n you are given a 5 point speed stat boost!\n";
 
                roomchoice = 7;
            }
            if (Fightoutcome = false)
            {
                roomchoice = 0;
            }
       
            return roomchoice;
            break;
        case 7: 
            Fightoutcome = fight(Unit,Boss);
            if (Fightoutcome = true)
            {
                roomchoice = 8;
            }
            if (Fightoutcome = false)
            {
                roomchoice = 0;
            }
            
            return roomchoice;
            break;
    }

    return roomchoice;
}
