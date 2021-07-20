// Given the root of a binary tree, return the sum of values of its deepest leaves.

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

int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int deepestLeavesSum(TreeNode *root)
{
    if (root == NULL)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<vector<int>> ans;
    vector<int> t;
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        if (current == NULL)
        {
            ans.push_back(t);
            t.clear();
            if (q.size() > 0)
            {
                q.push(NULL);
            }
        }
        else
        {
            t.push_back(current->val);
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }

    vector<int> last = ans[height(root) - 1];
    int sum = 0;
    for (int x : last)
    {
        sum += x;
    }
    return sum;
}