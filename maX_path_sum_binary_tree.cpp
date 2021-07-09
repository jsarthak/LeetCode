/*

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.
*/
#include<bits/stdc++.h>
using namespace std;

int answer;
int helper(TreeNode* root ){
    if (root == NULL){
        return 0;
    }
    int x = helper (root -> left);
    int y = helper (root -> right);
    answer = max(answer, x+y+root->val);
    return max(0,root->val + max(x,y));
}

int maxPathSum(TreeNode* root) {
    answer = INT_MIN;
    helper(root);
    return answer;
}