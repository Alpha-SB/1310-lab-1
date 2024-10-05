#include<iostream>
#include<fstream> 
#include<string>
#include<iomanip>
#include<cctype>
#include<climits>
#include "Forest.h"

#ifndef Character_H
#define Character_H

using namespace std;

class Character
{
    private:
    //Variable
    string name;
    int healthPoints;
    int attackStat;
    int speed;
    string* arrayOfItems;
    int numItems;
    

    public:
    //Function Prototypes
    Character();
    Character(string, int, int, int, int);
    ~Character();
    string getName() const;
    void setName(string);
    int getHealthPoints() const;
    void setHealthPoints(int);
    int getAttackStat() const;
    void setAttackStat(int);
    int getSpeed() const;
    void setSpeed(int);
    friend ostream& operator<<(ostream& , Character&);
    void setNumItems(string*);
    void printCharacters(Character*);
    string setArrayOfItems0();
    string setArrayOfItems00();//gives best item when user wins fight
    string setArrayOfItems1();
    string setArrayOfItems2();
    string setArrayOfItems22();//gives best item when user wins fight
    
};


#endif