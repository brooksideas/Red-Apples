#include <iostream>
#include <vector>

class binTree
{
public:
    struct binTreeNode
    {
        bool apple;
        binTreeNode *left;
        binTreeNode *right;
    };
    binTree();
    binTree(std::vector<bool>);
    ~binTree();
    int minTime();
private:
    void destroyTree(binTreeNode *);
    binTreeNode* buildTree(std::vector<bool> , binTreeNode *r,  int);
    int minTime(binTreeNode *r, int);
    binTreeNode *root;
};