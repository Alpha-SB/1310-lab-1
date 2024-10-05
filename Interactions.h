// this is the interactions class.h
#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include<iostream>
#include<fstream> 
#include<string>
#include<iomanip>
#include<cctype>
#include<climits>
#include"Character.h"
#include"Forest.h"
using namespace std;

class Interactions
{

    private:
        int logsize, damage, remaninghealth;
        string AttckerName, ReciverName;
        string* battlelog;
    public:
        Interactions();//defualt constructor
        Interactions(int,int,string,string);//overloaded constructor
        ~Interactions();//destructor
        void makebattlelog();//creates array from pointer. 
        int damagedelt(int);//function to calculate damage
        int characterremaninghealth(int,int);//function to calculate remanining hp
        bool fight(Character*,int);//function to have player and enemy fight
        string log(int,Interactions*);//saves battle statements to the battlelog array. 
        string getDamage() const;
        string getRH() const;
        string getAN() const;
        string getRN() const;
        void savelogtofile(fstream,string);//save the battle log to a file
        string savetolog(Interactions);//saves statement from fight to a string to be stored in the log. 
        int checkInput(int);//checks user inputed a int value.
};

#endif