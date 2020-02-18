/*
CPSC 360
Assignment 1

Christian Valencia
2275944
valen193@mail.chapman.edu
*/

#include "fileIO.h"

using namespace std;

int main(int argc, char const *argv[])
{

        if((argc > 0) && (argv[1] != NULL))
        {
            string filepath = argv[1];
            try
            {

            }
            catch(const invalid_argument& message)
            {
                cout << message.what() << endl;
                cout << "Invalid file." << endl;
            }
        }
        else
        {
            cout << "Please provide the file path for a text document" << endl;
        }

        cout << "\nThe program exited successfully." << endl;
    }
    return 0;

}
