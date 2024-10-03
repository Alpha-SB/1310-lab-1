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
        int damage, remaninghealth;
        string* battlelog;
    public:
        Interactions();
        ~Interactions();
        int damagedelt(int);
        int characterremaninghealth(int,int);
        string log(int,int,string,string);
        void savelogtofile(fstream,string);
        void fight(Character[], int);
        int runGame(int, Character[]);
        int damageInt(int);
        
        /* during a fight add each cout of x did x damage to x and x has x hp left
        to the string array battlelog then after the fight call a function that
        is a for loop that prints every element of the array into a txt file. */
};

#endif