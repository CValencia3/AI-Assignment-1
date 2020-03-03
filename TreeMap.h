#pragma once

#include "TreeNode.h"

class TreeMap
{
    //Tree of the map for robot nagivation
    public:
        TreeMap();
        //Initalized with size of map read from file
        TreeMap(int s);
        ~TreeMap();

        //Returns if a node exists at a position
        bool contains(pair<int,int> key);
        bool isEmpty();
        //recursive search sub function for contains
        bool rSearch(TreeNode* node, pair<int,int> k);
        //void debugPrint();

        //recursive walk through state space
        void populateTree(pair<int,int> pos, gameBoard* board);
        void recPopulate(TreeNode* node, gameBoard* board);
        void findAdjacentNodes(TreeNode* current, gameBoard* board);

        TreeNode* root;
        char** printArray;
        int size;

};
