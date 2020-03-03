#pragma once
#include <math.h>
#include <list>
#include <queue>

#include "TreeMap.h"
#include "gameBoard.h"

using namespace std;

class simulation
{
    public:
        simulation();
        simulation(gameBoard* g, int m);
        ~simulation();

        void run();

        void initSolution();
        pair<int,int> locate(gameBoard* g, char c);

        TreeNode* aStar(TreeMap* problem);
        void subA(TreeNode* node, TreeNode* child);

        bool inQ(TreeNode* n);
        bool inList(list<TreeNode*> explored, TreeNode* n);

        void populateTree();
        void recPopulate(TreeNode* node);

        bool goalTest(TreeNode* node);

        void findAdjacentNodes(TreeNode* current);

        double euclidianDistance(pair<int,int> pos, pair<int,int> goal);
        double manhattanDistance(pair<int,int> pos, pair<int,int> goal);

        void printBoard();
        void printSolution(TreeNode* end);

        TreeMap* problem;
        priority_queue< TreeNode *> fringe;
        list<TreeNode*> explored;
        gameBoard* board;
        gameBoard solution;
        pair<int,int> goal;
        int totalPath;
        int steps;
        vector<TreeNode*> path;
        int mode;

};
