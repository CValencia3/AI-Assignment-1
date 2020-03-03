/*
CPSC 360
Assignment 1

Christian Valencia
2275944
valen193@mail.chapman.edu
*/

#include "fileIO.h"
#include "simulation.h"

using namespace std;

int mode = 3;
// 0 = Strategy 1 - Euclidian Distance
// 1 = Strategy 2 - Manhattan Distance
// 2 = Strategy 3 - Euclidian Distance + cost of path so far
// 3 = Strategy 4 - Manhattan Distance + cost of path so far

int main(int argc, char const *argv[])
{

    if((argc > 0) && (argv[1] != NULL))
    {
        string filepath = argv[1];
        try
        {
            cout << endl << "Best-First Robot Navigation" << endl;
            fileIO f(filepath);
            //char** array = f.read();
            gameBoard g(f.read(), f.getSize());
            simulation sim(&g, mode);
            sim.run();
        }
        catch(const invalid_argument& message)
        {
            cout << message.what() << endl;
            cout << "Invalid file." << endl;
        }
        catch(const char*)
        {
            cout << "Board size too big." << endl;
        }
    }
    else
    {
        cout << "Please provide the file path for a text document" << endl;
    }

    cout << "\nThe program exited successfully." << endl;
    return 0;
}
