// Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

#include <bits/stdc++.h>
using namespace std;

int triangleNumber(vector<int> &nums)
{
    if (nums.size() < 3)
    {
        return 0;
    }
    int ans = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = n - 1; i > 1; i--)
    {
        int l = 0, r = i - 1;
        while (l < r)
        {
            if (nums[l] + nums[r] > nums[i])
            {
                ans += (r - l);
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 2, 3, 4};
    int ans = triangleNumber(nums);
    cout << ans << "\n";
    return 0;
}