//
//Given the root of a binary tree, return the average value of the 
//nodes on each level in the form of an array. 
//Answers within 10-5 of the actual answer will be accepted.


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

vector<double> averageOfLevels(TreeNode* root) {
    if (root == NULL){
        return {};
    }
    
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    vector<double> ans;
    double average = 0;
    double count = 0;
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        if (current == NULL){
            ans.push_back(average/count);
            average=0;
            count = 0;
            if (q.size()>0){
                q.push(NULL);
            }
        } else {
            average += current -> val;
            count++;
            if (current -> left) q.push(current ->left);
            if (current -> right)q.push(current->right);
        }
    }
    return ans;
}