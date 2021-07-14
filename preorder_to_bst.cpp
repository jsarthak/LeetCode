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

TreeNode *handler(vector<int> preorder)
{
    if (preorder.size() == 0)
        return NULL;
    vector<int> smaller;
    vector<int> greater;
    int root_val = preorder[0];
    TreeNode *root = new TreeNode(root_val);
    for (int i = 1; i < preorder.size(); i++)
    {
        if (root_val > preorder[i])
        {
            smaller.push_back(preorder[i]);
        }
        else
        {
            greater.push_back(preorder[i]);
        }
    }
    root->left = handler(smaller);
    root->right = handler(greater);
    return root;
}

TreeNode *bstFromPreorder(vector<int> preorder)
{
    return handler(preorder);
}

int main()
{
    return 0;
}