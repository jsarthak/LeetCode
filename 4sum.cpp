/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{

	int n = nums.size();
	if (n < 4)
	{
		return {};
	}

	sort(nums.begin(), nums.end());
	int k, l, sum;
	vector<vector<int>> ans;
	for (int i = 0; i < n - 3; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		for (int j = i + 1; j < n - 2; j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
			{
				continue;
			}
			k = j + 1;
			l = n - 1;
			while (k < l)
			{
				sum = nums[i] + nums[j] + nums[k] + nums[l];
				if (sum > target)
				{
					l--;
				}
				else if (sum < target)
				{
					k++;
				}
				else
				{
					ans.push_back({nums[i], nums[j], nums[k], nums[l]});
					while (k < l && nums[k] == nums[k + 1])
						k++;
					while (k < l && nums[l] == nums[l - 1])
						l--;
					k++;
					l--;
				}
			}
		}
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	while (n--)
	{
		int a;
		cin >> a;
		nums.push_back(a);
	}
	int target;
	cin >> target;
	vector<vector<int>> ans = fourSum(nums, target);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << '[' << " ";
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << ']' << " ";
	}
	cout << endl;
	return 1;
}