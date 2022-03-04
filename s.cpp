/// Template Testing code to understand how the main binTree is implemented 

#include <bits/stdc++.h>
#include <cmath>

using namespace std;

struct TreeNode
{
    int item;        // The data in this node.
    TreeNode *left;  // Pointer to the left subtree.
    TreeNode *right; // Pointer to the right subtree.
};

int counter = 0, level = 1, currentLevelFound = 0, onSameLevel = 0;

void preorderPrint(TreeNode *root, TreeNode *full)
{
    // Print all the items in the tree to which root points.
    // The item in the root is printed first, followed by the
    // items in the left subtree and then the items in the
    // right subtree.
    if (root != NULL)
    {                                     // (Otherwise, there's nothing to print.)
        cout << root->item << " ";        // Print the root item.
        preorderPrint(root->left, full);  // Print items in left subtree.
        preorderPrint(root->right, full); // Print items in right subtree.

        // if clause to hold values
        if (root->item == 1)
        {
            // calculate the current level in the Binary Tree that the element one is found on
            level = 1;
            int exponent = 1;
            while (std::pow(2, exponent) < counter)
            {
                exponent++;
            }

            level = exponent + 1;

            cout << "Address => " << &root << endl;
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

TreeNode *newNode(int data)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->item = data;
    node->left = node->right = NULL;
    return (node);
}

// Function to insert nodes in level order
TreeNode *insertLevelOrder(int arr[], TreeNode *root,
                           int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        TreeNode *temp = newNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr,
                                      root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr,
                                       root->right, 2 * i + 2, n);
    }
    return root;
}

// Driver program to test above function
int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6};
    // int arr[] = {0, 0, 1, 0, 1, 0, 0};
    //  int arr[] = {0, 0, 0, 1, 0, 0, 0, 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,0 ,1 ,1};
    // int arr[] = {0, 0, 0, 0, 0, 0, 0};
    int arr[] = {0, 0, 1, 0, 0, 0, 0 ,0 ,0 ,0 , 0 , 1 , 0 , 1 , 0};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\n SIZE Preorder ->" << n << endl;

    TreeNode *root = insertLevelOrder(arr, root, 0, n);

    cout << "\n IN Preorder ->" << endl;

    preorderPrint(root, root);

    cout << "\n Traverse Tree Contains Counter" << counter << endl;

    cout << "\n Level Counter" << level << endl;
    if (onSameLevel > 0)
    {
        onSameLevel -= 1;
    }
    cout << "\n Level onSameLevel" << onSameLevel << endl;

    int mini = (currentLevelFound + onSameLevel) * 2;
    cout << "\n Result Counter" << mini << endl;
}