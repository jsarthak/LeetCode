// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;

int maxDepth(TreeNode* root){
	if (root == NULL){
		return NULL;
	}

	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	int ans = 0;
	while(!q.empty()){
		TreeNode* current = q.front();
		q.pop();
		if(current == NULL){
			ans ++;
			if (q.size() > 0){
				q.push(NULL);
			}
		} else{
			if (current -> left) q.push(current->left);
			if (current -> right )q.push(current -> right);
		}
	}
	return ans;
}

// other solution
// Recursive
// int maxDepth(TreeNode* root){
// 	if (!root ) return 0;
// 	return 1 + max((maxDepth(root -> left)), maxDepth(root -> right));
// }