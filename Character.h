#include <iostream>
#include <iomanip>

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
    Character();
    Character(string, int, int, int);
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
    void setArrayOfItems0(string, int);
    void setArrayOfItems1(string numItems, int i);
    void setArrayOfItems2(string, int );
};


#endif