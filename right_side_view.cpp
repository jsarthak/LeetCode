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

void right(vector<int> &val, TreeNode *root, int depth)
{
    if (root == NULL)
        return;
    if (val.size() == depth)
        val.push_back(root->val);
    right(val, root->right, depth + 1);
    right(val, root->left, depth + 1);
}
vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    int depth = 0;
    right(ans, root, depth);
    return ans;
}
