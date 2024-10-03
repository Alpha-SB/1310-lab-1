#include <iostream>

using namespace std;

int checkInput(int);

int checkInput(int num)
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