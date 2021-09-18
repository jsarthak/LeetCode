
// Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

// If there are no nodes with an even-valued grandparent, return 0.

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
    int helper(TreeNode *root)
    {
        int sum = 0;
        if (root->left)
        {
            sum += (root->left->left ? root->left->left->val : 0) + (root->left->right ? root->left->right->val : 0);
        }
        if (root->right)
        {
            sum += (root->right->left ? root->right->left->val : 0) + (root->right->right ? root->right->right->val : 0);
        }
        return sum;
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;

        if (root->val % 2 == 0)
        {
            ans += helper(root);
        }

        ans += sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);

        return ans;
    }
};