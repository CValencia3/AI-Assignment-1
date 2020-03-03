#include "simulation.h"

using namespace std;

simulation::simulation(){}
simulation::simulation(gameBoard* g, int m)
{
    mode = m;
    board = g;
    problem = new TreeMap(board->size);
    initSolution();
    goal = locate(board, 'g');
}
simulation::~simulation(){}


void simulation::run()
{
    cout << "Running program..." << endl;

    pair <int,int> init = locate(board, 'i');
    pair <int,int> pos = init;

    problem->populateTree(pos, board);

    fringe.push(problem->root);

    TreeNode* endNode = aStar(problem);

    printSolution(endNode);

}

void simulation::initSolution()
{
    solution = gameBoard(board->world,board->size);
    board->copy(&solution);
}

pair<int,int> simulation::locate(gameBoard* g, char c)
{
    for (size_t y = 0; y < g->size; y++)
    {
        for (size_t x = 0; x < g->size; x++)
        {
            if (g->world[x][y] == c)
            {
                pair <int, int> p;
                p.first = x, p.second = y;
                return p;
            }
        }
    }
}

TreeNode* simulation::aStar(TreeMap* problem)
{
    cout << "Starting search..." << endl;
    steps = 1;
    totalPath = 0;
    TreeNode* child;
    TreeNode* node;

    while(steps < 500)
    {
        if (fringe.empty()) return NULL;
        else
        {
            node = fringe.top();
            fringe.pop();

            if(goalTest(node))
            {
                cout << "Goal found!" << endl;
                return node;
            }

            explored.push_front(node);

            if (node->weight < fringe.top()->weight)
            {
                steps ++;
            }

            child = node->up;
            subA(node, child);
            child = node->right;
            subA(node, child);
            child = node->down;
            subA(node, child);
            child = node->left;
            subA(node, child);
        }
    }
}

void simulation::subA(TreeNode* node, TreeNode* child)
{
    if (child == NULL) return;

    switch (mode)
    {
        case 0: child->weight = euclidianDistance(child->key, goal);
            break;
        case 1: child->weight = manhattanDistance(child->key, goal);
            break;
        case 2: child->weight = (euclidianDistance(child->key, goal) + steps);
            break;
        case 3: child->weight = (manhattanDistance(child->key, goal) + steps);
            break;
    }

    fringe.push(child);
    child->path = node;
}

bool simulation::inQ(TreeNode* n)
{
    bool found = false;
    priority_queue<TreeNode*> copy;
    while(!fringe.empty())
    {
        copy.push(fringe.top());
        if (copy.top() == n) found = true;
        fringe.pop();
    }
    while(!copy.empty())
    {
        fringe.push(copy.top());
        copy.pop();
    }
    return found;
}

bool simulation::inList(list<TreeNode*> explored, TreeNode* n)
{
    list <TreeNode*> :: iterator it;
    for (it = explored.begin(); it != explored.end(); ++it)
    {
        if (*it == n) return true;
    }
}

bool simulation::goalTest(TreeNode* node)
{
    if (node == NULL) return false;
    return (node->value == 'g');
}

double simulation::euclidianDistance(pair<int,int> pos, pair<int,int> goal)
{
    double dx = (pos.first - goal.first);
    double dy = (pos.second - goal.second);
    return sqrt(dx*dx + dy*dy);
}

double simulation::manhattanDistance(pair<int,int> pos, pair<int,int> goal)
{
    return abs((pos.first - goal.first)) + abs((pos.second - goal.second));
}
void simulation::printBoard()
{
    cout << "Board:" << endl;
    board->print();
}

void simulation::printSolution(TreeNode* end)
{
    cout << "Solution:" << endl;
    for(TreeNode* curr = end->path; curr != NULL; curr= curr->path)
    {
        totalPath += curr->weight;
        solution.world[curr->key.first][curr->key.second] = 'o';
    }

    totalPath += steps;

    solution.print();

    cout << endl << "Path Cost: " << totalPath << endl;
}
