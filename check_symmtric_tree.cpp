// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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

bool isMirror(TreeNode *a, TreeNode *b)
{
    if (!a && !b)
        return true;
    if (a && !b)
        return false;
    if (!a && b)
        return false;
    return (a->val == b->val && isMirror(a->left, b->right) && isMirror(a->right, b->left));
}

bool isSymmetric(TreeNode *root)
{
    return isMirror(root->left, root->right);
}