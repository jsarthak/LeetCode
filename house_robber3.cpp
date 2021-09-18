

// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

// Example 1:

// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

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
    pair<int, int> dfs(TreeNode *root)
    {
        if (!root)
            return {0, 0};

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        int withRoot = root->val + left.second + right.second;
        int withoutRoot = max(left.first, left.second) + max(right.first, right.second);
        return {withRoot, withoutRoot};
    }
    int rob(TreeNode *root)
    {
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }
};