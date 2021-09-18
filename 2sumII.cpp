/*
Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.

Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.

The tests are generated such that there is exactly one solution. You may not use the same element twice.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
	int n = numbers.size();
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int valLow = numbers[low];
		int valHigh = numbers[high];

		if (valHigh + valLow == target)
		{
			return {low + 1, high + 1};
		}
		else if (valHigh + valLow > target)
		{
			high--;
		}
		else
		{
			low++;
		}
	}
	return {-1, -1};
}

int main()
{
	// accept an input equal to nums size
	int n;
	cin >> n;
	// while n add elements to a array
	vector<int> nums;
	while (n--)
	{
		int k;
		cin >> k;
		nums.push_back(k);
	}
	// get the target sum
	int target;
	cin >> target;

	vector<int> ans = twoSum(nums, target);
	cout << "[" << ans[0] << "," << ans[1] << "]" << endl;

	return 1;
}