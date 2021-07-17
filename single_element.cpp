// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

// Follow up: Your solution should run in O(log n) time and O(1) space.
#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (mid % 2)
        {
            if (nums[mid] == nums[mid - 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        else
        {
            if (nums[mid] != nums[mid + 1])
            {
                right = mid;
            }
            else
            {

                left = mid + 1;
            }
        }
    }
    return nums[left];
}