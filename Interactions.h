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
using namespace std;

class Interactions
{

    private:
        int logsize, damage, remaninghealth;
        string AttckerName, ReciverName;
        string* battlelog;
    public:
        Interactions();
        Interactions(int,int,string,string);
        ~Interactions();
        void makebattlelog();
        int damagedelt(int);
        int characterremaninghealth(int,int);
        void fight(Character,int);
        string log(int,Interactions*);
        string getDamage() const;
        string getRH() const;
        string getAN() const;
        string getRN() const;
        void savelogtofile(fstream,string);
        string savetolog(Interactions);
        /* during a fight add each cout of x did x damage to x and x has x hp left
        to the string array battlelog then after the fight call a function that
        is a for loop that prints every element of the array into a txt file. */
        void fight(Character*, int);
        int runGame(int, Character*);
};

#endif