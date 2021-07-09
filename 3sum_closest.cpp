/*

Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.
*/

#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> nums, int target)
{
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int j, k, sum = nums[0] + nums[1] + nums[n - 1];
	int ans = sum;
	for (int i = 0; i < n - 2; i++)
	{
		j = i + 1;
		k = n - 1;
		while (j < k)
		{
			sum = nums[i] + nums[j] + nums[k];
			if (sum < target)
			{
				j++;
			}
			else
			{
				k--;
			}
			if (abs(sum - target) < abs(ans - target))
				ans = sum;
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
	cout << threeSumClosest(nums, target);
	return 1;
}