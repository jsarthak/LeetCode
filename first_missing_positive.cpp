
// Given an unsorted integer array nums, find the smallest missing positive integer.

// You must implement an algorithm that runs in O(n) time and uses constant extra space.

#include <bits/stdc++.h>
using namespace std;
class Solution
{

    // set<int> vals;
    // for(auto x : nums){
    //     vals.insert(x);
    // }
    // int ans = 1;
    // while(vals.count(ans)) ans++;
    // return ans;

public:
    int firstMissingPositive(vector<int> &nums)
    {

        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0)
            {
                nums[i] = INT_MAX;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (abs(nums[i]) - 1 < n)
            {
                if (nums[abs(nums[i]) - 1] > 0)
                    nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                ans++;
            }
            else
            {
                return i + 1;
            }
        }

        return ans;
    }
};