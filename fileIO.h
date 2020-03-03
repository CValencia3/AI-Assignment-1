#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class fileIO
{
    //A class for parsing a text file
    public:
        // Default constructor
        fileIO();
        // Overloaded constructor
        fileIO(string filepath);
        // Desctructor
        ~fileIO();

        // Method returns an array generated from the file given
        char** read();
        // reads x,y
        //  or col,row
        int getSize();

        string filepath;
        char **output;
        int length;
};
