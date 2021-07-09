
/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
*/

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int valMid = nums[mid];
        int valLow = nums[low];
        int valHigh = nums[high];

        if (valMid == target)
        {
            return true;
        }

        if (valLow == valMid && valMid == valHigh)
        {
            low++;
            continue;
        }

        if (valMid <= valHigh)
        {
            if (target > valMid && target <= valHigh)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            if (valLow <= target && target < valMid)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return false;
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

    cout << search(nums, target);
    return 1;
}