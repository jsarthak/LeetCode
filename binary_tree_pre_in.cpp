//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

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

TreeNode *insert(vector<int> &preorder, vector<int> &inorder, int pStart, int iStart, int iEnd)
{

    if (pStart > preorder.size() - 1 || iStart > iEnd)
        return NULL;
    TreeNode *root = new TreeNode(preorder[pStart]);
    int index = 0;
    for (index = iStart; index <= iEnd; index++)
    {
        if (inorder[index] == root->val)
        {
            break;
        }
    }

    root->left = insert(preorder, inorder, pStart + 1, iStart, index - 1);
    root->right = insert(preorder, inorder, pStart + index - iStart + 1, index + 1, iEnd);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return insert(preorder, inorder, 0, 0, inorder.size() - 1);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    buildTree(preorder, inorder);

    return 0;
}