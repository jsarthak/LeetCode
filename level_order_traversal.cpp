//Given the root of a binary tree,
//return the level order traversal of its nodes' values.
//(i.e., from left to right, level by level).

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

vector<vector<int>> levelOrder(TreeNode *root)
{
	vector<vector<int>> ans;
	if (root == NULL)
	{
		return ans;
	}
	vector<int> temp;
	queue<TreeNode *> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty())
	{
		TreeNode *current = q.front();
		q.pop();
		if (current == NULL)
		{
			ans.push_back(temp);
			temp.clear();
			if (q.size() > 0)
			{
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

int main()
{
	return 0;
}
