
// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int goal = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + nums[i] >= goal)
        {
            goal = i;
        }
    }
    return goal == 0;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    bool ans = canJump(nums);
    cout << ans << "\n";
    return 0;
}