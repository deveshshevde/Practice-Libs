#include "tree.h"

TreeNode_t* TreeStructure()
{
    struct TreeNode* root =(TreeNode_t*)malloc(sizeof(TreeNode_t));
    root->data = 0;
    root->leftTreeNode = NULL;
    root->rightTreeNode = NULL;
    return root;
}