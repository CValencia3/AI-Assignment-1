#pragma once
#include <stdlib.h>
#include <utility>
#include <iostream>

using namespace std;

class gameBoard
{
    //A class to contain a 2D array taken in from file IO class
    public:
        gameBoard();
        gameBoard(char**, int size);
        ~gameBoard();

        void print();
        //Returns the char at location given
        char lookup(pair<int,int> p);
        void copy(gameBoard* copy);

        int size;
        int goal;
        int inital;
        //The 2D array where char are stored
        char **world;
};
