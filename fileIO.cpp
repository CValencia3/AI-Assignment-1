#include "fileIO.h"

using namespace std;

fileIO::fileIO()
{
    filepath = "input.txt";
    getSize();

}
fileIO::fileIO(string fp)
{
    filepath = fp;
    getSize();
}
fileIO::~fileIO()
{

}

char** fileIO::read()
{
    ifstream file (filepath);

    string line;
    int count = 0;

    if(file.is_open())
    {
        file.clear();
        file.seekg(0);

        getline(file,line);

        //Declare new 2D array
        output = new char*[length];
        for (size_t x = 0; x < length; x++)
        {
            output[x] = new char[length];
        }

        while (getline (file, line))
        {
            for (size_t i = 0; i < length; i++)
            {
                output[i][count] = line[i];
            }

            count++;
        }

        file.close();
    }
    else
    {
        cout << "Invalid filepath" << endl;
    }

    return output;
}

int fileIO::getSize()
{
    ifstream file (filepath);
    string line;
    if(file.is_open())
    {
        file.clear();
        file.seekg(0);
        getline(file,line);
        length = stoi(line);
        if (length > 80)
        {
            file.close();
            throw "Simulation size too big.";
        }
    }
    file.close();

    return length;
}
