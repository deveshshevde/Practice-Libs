#include "../Trees/tree.h"
#include "assert.h"



/*
    Test case for this !!
*/


void InOrderTraversalAndCollect(TreeNode_t* node, int* result, int* index)
{
    if (node == NULL) return;

    InOrderTraversalAndCollect(node->leftTreeNode, result, index);
    result[(*index)++] = node->data;
    InOrderTraversalAndCollect(node->rightTreeNode, result, index);
}

void test_AddValueToTree()
{
    printf("Running test_AddValueToTree...\n");
    
    // Create the root and add values to the tree
    TreeNode_t* root = CreateRoot(10);
    AddValueTotree(5, root);
    AddValueTotree(15, root);
    AddValueTotree(3, root);
    AddValueTotree(7, root);
    AddValueTotree(20, root);

    // Perform inorder traversal and verify the structure
    int result[6] = {0};
    int index = 0;
    InOrderTraversalAndCollect(root, result, &index);

    // Expected result should be sorted: 3, 5, 7, 10, 15, 20
    int expected[6] = {3, 5, 7, 10, 15, 20};
    for (int i = 0; i < 6; ++i) {
        assert(result[i] == expected[i]);
    }

    printf("test_AddValueToTree passed!\n");
}
// Test CreateRoot function
void test_CreateRoot()
{
    printf("Running test_CreateRoot...\n");
    
    TreeNode_t* root = CreateRoot(10);
    assert(root != NULL);                 // Check that root is not NULL
    assert(root->data == 10);             // Check that data is correctly set
    assert(root->leftTreeNode == NULL);   // Ensure left child is NULL
    assert(root->rightTreeNode == NULL);  // Ensure right child is NULL

    free(root); // Clean up the allocated memory
    printf("test_CreateRoot passed!\n");
}

// Test insertion into an empty tree (root is NULL)
void test_AddToEmptyTree()
{
    printf("Running test_AddToEmptyTree...\n");
    
    TreeNode_t* root = NULL;
    root = AddValueTotree(10, root);
    assert(root != NULL);                 // Ensure the new root is created
    assert(root->data == 10);             // Check that data is correctly set

    free(root);
    printf("test_AddToEmptyTree passed!\n");
}


int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    test_CreateRoot();        // Test root creation
    test_AddValueToTree();    // Test adding values to the tree
    test_AddToEmptyTree();    // Test adding to an empty tree

    printf("All tests passed!\n");
    return 0;
}

