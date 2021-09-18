// Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

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

void inorder(vector<int> &result, TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(result, root->left);
    result.push_back(root->val);
    inorder(result, root->right);
}

int kthSmallest(TreeNode *root, int k)
{
    vector<int> result;
    inorder(result, root);
    return result[k - 1];
}