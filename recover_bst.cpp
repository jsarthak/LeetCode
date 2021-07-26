
// You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

// Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    TreeNode *min = NULL;
    TreeNode *prev = NULL;
    bool found = false;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        if (root->val < prev->val && root->val < min->val)
        {
            min = root;
            found = true;
        }
        else if (!found)
        {
            prev = root;
        }
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        min = new TreeNode(INT_MAX);
        prev = new TreeNode(INT_MIN);
        inorder(root);
        swap(min->val, prev->val);
    }
};