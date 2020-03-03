#include "gameBoard.h"

using namespace std;

gameBoard::gameBoard(){}
gameBoard::gameBoard(char** file, int s)
{
    world = file;
    size = s;
}
gameBoard::~gameBoard(){}


void gameBoard::print()
{
    for (size_t y = 0; y < size; y++)
    {
        for (size_t x = 0; x < size; x++)
        {
            cout << world[x][y];
        }
        cout << endl;
    }
}

char gameBoard::lookup(pair<int,int> p)
{
    return world[p.first][p.second];
}

void gameBoard::copy(gameBoard* copy)
{
    for (size_t y = 0; y < size; y++)
    {
        for (size_t x = 0; x < size; x++)
        {
            copy->world[x][y] = world[x][y];
        }
    }
}
