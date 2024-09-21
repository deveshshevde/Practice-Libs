#include <stdlib.h>
#include <stdio.h>
#pragma once


typedef enum 
{
    OK = 0,
    FAILURE = 1
}status_t;

typedef struct  TreeNode
{
    int data;
    struct TreeNode* rightTreeNode;
    struct TreeNode* leftTreeNode;
}TreeNode_t;

TreeNode_t* TreeStructure(void);