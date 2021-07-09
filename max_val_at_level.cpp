//
//Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).


#include<bits/stdc++.h>
using namespace std;
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
vector<int> largestValues(TreeNode* root){
	if (root == NULL){
		return {};
	}
	vector<int> ans;
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	int maxVal = INT_MIN;
	while(!q.empty()){
		TreeNode* current = q.front();
		q.pop();
		if (current == NULL){
			ans.push_back(maxVal);
			maxVal = INT_MIN;
			if(q.size()>0){
				q.push(NULL);
			}
		} else{
			maxVal = max(maxVal, current->val);
			if (current-> left) q.push(current->left);
			if (current->right)q.push(current->right);
		}
	}
	return ans;
}


int main(){}