#pragma once

#include "gameBoard.h"

using namespace std;

class TreeNode
{
    //Component class of the Tree Map
    public:
        TreeNode();
        //Takes in coordinates and refrence table of char
        TreeNode(pair<int,int> k, gameBoard* g);
        ~TreeNode();

        //Overloaded operator so class can be used in priority_queue
        bool operator()( const TreeNode& lhs, const TreeNode& rhs ) const
            {return lhs.weight > rhs.weight;};

        //Key is coords, value is type of space, weight is distance
        pair<int,int> key;
        char value;
        double weight;

        //Keep track of where we have been
        TreeNode* path;

        //Adjacent Neighbors
        TreeNode* left;
        TreeNode* right;
        TreeNode* up;
        TreeNode* down;

};
