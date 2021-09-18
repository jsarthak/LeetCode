// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> pref(nums.size(), 1);
    vector<int> suff(nums.size(), 1);
    vector<int> ans;
    suff[nums.size() - 2] = nums[nums.size() - 1];
    for (int i = 1; i < nums.size(); i++)
    {
        pref[i] = pref[i - 1] * nums[i - 1];
    }

    for (int i = nums.size() - 3; i >= 0; i--)
    {
        suff[i] = suff[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        ans.push_back(pref[i] * suff[i]);
    }
    return ans;
}
