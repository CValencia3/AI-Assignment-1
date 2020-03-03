#include "TreeMap.h"


TreeMap::TreeMap(){}
TreeMap::TreeMap(int s)
{
    size = s;
    root = NULL;

    printArray = new char*[size];
    for (size_t x = 0; x < size; x++)
    {
        printArray[x] = new char[size];
    }
    for (size_t y = 0; y < size; y++)
    {
        for (size_t x = 0; x < size; x++)
        {
            printArray[x][y] = 'X';
        }
    }
}
TreeMap::~TreeMap(){}


bool TreeMap::contains(pair<int,int> key)
{
    if(isEmpty()) return false;

    TreeNode* start = root;
    return rSearch(start, key);

}

bool TreeMap::isEmpty()
{
    return (root == NULL);
}

bool TreeMap::rSearch(TreeNode* node, pair<int,int> k)
{
    if(node == NULL) return false;

    if(node->key == k) return true;

    if (rSearch(node->left,  k)) return true;
    if (rSearch(node->right, k)) return true;
    if (rSearch(node->up,    k)) return true;
    if (rSearch(node->down,  k)) return true;
}

// void TreeMap::debugPrint()
// {
//     for (size_t y = 0; y < size; y++)
//     {
//         for (size_t x = 0; x < size; x++)
//         {
//             cout << printArray[x][y];
//         }
//         cout << endl;
//     }
// }

void TreeMap::populateTree(pair<int,int> pos, gameBoard* board)
{
    root = new TreeNode(pos, board);

    recPopulate(root,board);
}

void TreeMap::recPopulate(TreeNode* node, gameBoard * board)
{
    if (node == NULL) return;

    //printArray[node->key.first][node->key.second] = node->value;
    findAdjacentNodes(node, board);

    recPopulate(node->left, board);
    recPopulate(node->right, board);
    recPopulate(node->up,  board);
    recPopulate(node->down, board);
}

void TreeMap::findAdjacentNodes(TreeNode* current, gameBoard* board)
{
    pair<int,int> pos = current->key;

    //up
    if (pos.second - 1 > -1)
    {
        pos.second--;
        if (board->lookup(pos) != '+' && !contains(pos))
        {
            current->up = new TreeNode(pos, board);
        }
        pos.second++;
    }

    //down
    if (pos.second + 1 < board->size)
    {
        pos.second++;
        if (board->lookup(pos) != '+' && !contains(pos))
        {
            current->down = new TreeNode(pos, board);
        }
        pos.second--;
    }

    //left
    if(pos.first -1 > -1)
    {
        pos.first--;
        if (board->lookup(pos) != '+' && !contains(pos))
        {
            current->left = new TreeNode(pos, board);
        }
        pos.first++;
    }

    //right
    if(pos.first +1 < board->size)
    {
        pos.first++;
        if (board->lookup(pos) != '+' && !contains(pos))
        {
            current->right = new TreeNode(pos, board);
        }
        pos.first--;
    }
}
