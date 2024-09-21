#include "tree.h"

TreeNode_t* CreateRoot(int root_Data)
{
    TreeNode_t* root = (TreeNode_t*)malloc(sizeof(TreeNode_t));
    if (root == NULL) {
        printf("Memory allocation failed for root node\n");
        return NULL;
    }
    root->data = root_Data;
    root->leftTreeNode = NULL;
    root->rightTreeNode = NULL;
    return root;
}
TreeNode_t* AddValueTotree(int data , TreeNode_t* root)
{

    if(root == NULL) 
    {
    struct TreeNode* newNode =(TreeNode_t*)malloc(sizeof(TreeNode_t));
    if(newNode==NULL)printf("Mem alloc faile");return NULL;
    newNode->data = data;
    newNode->leftTreeNode = NULL;
    newNode->rightTreeNode = NULL;
    return newNode;
    }
    if(data >= root->data){
        root->rightTreeNode =  AddValueTotree(data, root->rightTreeNode);
    }
    else{
        root->leftTreeNode=  AddValueTotree(data, root->leftTreeNode);
    }
    return root;
}