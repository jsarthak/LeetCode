
// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int height(TreeNode *root, int &d)
    {
        if (root == NULL)
            return 0;
        int left = height(root->left, d);
        int right = height(root->right, d);
        d = max(left + right, d);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int d = 0;
        height(root, d);
        return d;
    }
};