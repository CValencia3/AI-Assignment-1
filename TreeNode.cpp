#include "TreeNode.h"

TreeNode::TreeNode()
{
    left = up = down = right = path = NULL;
    key = {0,0};
    weight = 0;
}
TreeNode::TreeNode(pair<int,int> k, gameBoard* g)
{
    left = up = down = right = path = NULL;
    key = k;
    value = g->lookup(k);
    weight = 0;
}
TreeNode::~TreeNode(){}
