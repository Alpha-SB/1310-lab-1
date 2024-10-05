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
    return WinLose;
}


int Interactions::checkInput(int num)
{
   
    while(!(cin >> num))
    {
        cout << "Please enter a valid number" << endl;
        cin.clear(); //clears all stream bits (good, bad, eof, fail)
        cin.ignore(10000, '\n'); //removes up to 10000 characters from buffer until a newline is removed
        cout << "\nEnter a number: ";
    }
    return num;
}