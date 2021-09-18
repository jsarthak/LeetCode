
//Given the root of a binary tree, return the sum of all left leaves.

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
    void solve(TreeNode *prev, TreeNode *root, int &sum)
    {
        if (root == NULL)
            return;
        if (!root->left && !root->right)
        {
            if (prev->left == root)
                sum += root->val;
        }

        solve(root, root->left, sum);
        solve(root, root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {

        int sum = 0;
        solve(root, root, sum);
        return sum;
    }
};