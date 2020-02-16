//remember to comile with g++ after each change 
// in visual studio #include "stdafx.h" must be the first include

#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>

using namespace std;

int main(int argc, const char** argv) {

    cout << "hello sami C++ do it dont dream it" <<endl;
    cout << "enter an age number pls" <<endl;
    string sAge;
    cin >> sAge;
    cout << sAge << endl;
    int nAge =stoi(sAge); //string to int
    cout <<nAge <<endl;
    char letterZ = 'z'; //alpha is a letter 
    char letterB = ',';
	char num5 = '5';
	char aSpace = ' ';
	cout << "is Z a letter or number \n" << isalnum(letterZ) <<endl;  //returns true if letter or num
    //isalpha() checks if letter, isdigit()
    cout << "is B a letter or number \n" << isalnum(letterB) <<endl; //returns true if letter or num
    cout << "is num5 a letter  \n" << isalpha(num5) <<endl; //returns true if letter 
     cout << "is num5 a number  \n" << isdigit(num5) <<endl; //returns true if digit

    cout << "is aspace a space \n" << isspace(aSpace) <<endl; //returns true if space

    if((nAge <= 39) && (nAge>=20))  {
        cout <<"this is an important young man\n";
    } else if ((nAge <= 70) && (nAge>39))
    {
     cout <<"you are a boomer now\n";  
    } else if ((nAge > 70) && (nAge<=120))
    {
     cout <<"you are a DEAD now\n";  
    }


    bool canIvote = (nAge>=18) ? true : false;
    //out.setf(ios::boolalpha); // changes true false from numbers to word true or false
    cout <<"can I vote ? :" << (canIvote? "YES": "no") << endl;



    //in c++ true is any value above 0, so you can get an 8 for example
    //in c++ false is 0

	// remember cin takes strings , so must convert it to an int after and store it in an int to use


    cin.ignore(); // this line causes program to wait for input but ignores it, just hit enter

    return 0;
}

//compile like > g++ main.cpp -o prog

// in kali linux might need to install g++ do this 
//sudo apt-get update
//sudo apt-get upgrade
//sudo apt-get install build-essential
//g++ -v 
//there is a sudo apt-get install g++ also if above didnt work but it should not be necessary.

// to compile in visual studio, visual c++ console application
// make sure the first include is #include "stdafx.h" has to come before all other includes.

