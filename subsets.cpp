// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> subset;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    subset.push_back(nums[j]);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};