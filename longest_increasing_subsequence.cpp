
// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7]

#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{

    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
        if (it == ans.end())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            *it = nums[i];
        }
    }

    return ans.size();
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums);
    return 0;
}