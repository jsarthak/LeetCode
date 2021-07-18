
// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

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
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int ans = 0;
        int sum = INT_MIN;
        int levelsum = 0;
        map<int, int> x;
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            if (current == NULL)
            {
                x.insert({levelsum, ++ans});
                sum = max(sum, levelsum);
                if (q.size() > 0)
                {
                    q.push(NULL);
                }
                levelsum = 0;
            }
            else
            {
                levelsum += current->val;
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
        }
        return x[sum];
    }
};