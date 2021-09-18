
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

int countNodes(TreeNode *root)
{

    if (root == NULL)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    int ans = 0;
    vector<int> temp;
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        if (current == NULL)
        {
            ans += temp.size();
            if (q.size() > 0)
            {
                temp.clear();
                q.push(NULL);
            }
        }
        else
        {
            temp.push_back(current->val);
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
    return ans;
}