#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
#include "binTree.h"

using namespace std;

// Mirroring Struct
struct TreeNode
{
    int item;        // The data in this node. True is 1 and False is 0
    TreeNode *left;  // Pointer to the left subtree.
    TreeNode *right; // Pointer to the right subtree.
};

int counter = 0, level = 1, currentLevelFound = 0, onSameLevel = 0;
/* Helper function that allocates a
new mirror node as the following 
For True it mirrors as 1 
For False it mirrors as 0
*/
TreeNode *newMirrorNode(int data)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->item = data;
    node->left = node->right = NULL;
    return (node);
}

// Function to insert nodes in level order , it mirrors the main build tree with 0's and 1's 
TreeNode *mirrorBuildTree(int arr[], TreeNode *root,
                           int i, int n)
{

    // Base case for recursion
    if (i < n)
    {
        TreeNode *temp = newMirrorNode(arr[i]);
        root = temp;

        // insert left child
        root->left = mirrorBuildTree(arr,
                                      root->left, 2 * i + 1, n);

        // insert right child
        root->right = mirrorBuildTree(arr,
                                       root->right, 2 * i + 2, n);
    }
    return root;
}
void preorderPrint(TreeNode *root)
{
    // Print all the items in the tree to which root points.
    // The item in the root is printed first, followed by the
    // items in the left subtree and then the items in the
    // right subtree.

    if (root != NULL)
    {                               
        cout << root->item << " ";  // Print the root apple item True(1) and False(0).
        preorderPrint(root->left);  // Print apples in left subtree.
        preorderPrint(root->right); // Print apples in right subtree.

        // if clause to hold values
        if (root->item == 1)
        {
    // calculate the current level in the Binary Tree that the element one is found on
    //       0  --------- 1st level width = 1 =>  2 raised to the power of 0
    //     /   \
    //    0     1 -------- 2nd level width = 2 =>  2 raised to the power of 1
    //   / \   / \  
    //  0   1 0   0 -------3rd level width = 4 => 2 raised to the power of 2

    // Whenever the exponent increases that means we moved on deeper level on the tree
            level = 1;
            int exponent = 1;
            while (std::pow(2, exponent) < counter)
            {
                exponent++;
            }

            level = exponent + 1;

            // if the level One is found on is similar to the current level increament level
            // because we have similar values on the same level
            if (currentLevelFound == level)
            {
                onSameLevel += 2;
            }
            else
            {
                currentLevelFound = level; // if we find a level not previously visited
            }
        }
        else
        {

            // increase the count of the binary tree elements by one
            counter++;
        }
    }
}

binTree::binTree(vector<bool> apples)
{
    int size = apples.size();
    int newTreeArr[size];
    for (size_t i = 0; i < size; i++)
    {

        // convert the true to 0 and false to 1
        // for preordering the tree
        newTreeArr[i] = apples[i];
    }

    // Build the Apples Tree with Bool Value 
     binTree::binTreeNode *tree = buildTree(apples, tree, 0);
 

    TreeNode *r = mirrorBuildTree(newTreeArr, r, 0, size);
    preorderPrint(r);
    minTime(root , size);
}

int binTree::minTime(binTree::binTreeNode *r, int n)
{
    // subtract one if at least 2 items are found on the same binary level
    if (onSameLevel > 0)
    {
        onSameLevel -= 1;
    } 
    
    // Multiply the level with the current deepest level that True is found 
    int mini = (currentLevelFound + onSameLevel) * 2;
    cout << "\n Minimum Time Required => \t" << mini << endl;
    return mini;
}



binTree::binTreeNode *newNode(bool data)
{
    binTree::binTreeNode *node = (binTree::binTreeNode *)malloc(sizeof(binTree::binTreeNode));
    node->apple = data;
    node->left = node->right = NULL;
    return (node);
}

binTree::binTreeNode *binTree::buildTree(std::vector<bool> apples, binTreeNode *r, int i)
{
    // Get the size of the vector
    int n = sizeof(apples) / sizeof(apples[0]);

    // Base case for recursion
    if (i < n)
    {
        root = newNode(apples[i]);

        // insert left child
        root->left = buildTree(apples,
                               root->left, 2 * i + 1);

        // insert right child
        root->right = buildTree(apples,
                                root->right, 2 * i + 2);
    }

    return root;
}

// Delete the Tree
binTree::~binTree()
{

}

// Delete this Test code once we are done testing 
int main()
{
    // Insert for testing purposes only

    std::vector<bool> apples;

    apples.push_back(false);
    apples.push_back(false);
    apples.push_back(true);
    apples.push_back(false);
    apples.push_back(true); 
    apples.push_back(false);
    apples.push_back(false);   
 
    binTree binTree(apples);
}