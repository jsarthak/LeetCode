
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.

#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    //next_permutation(nums.begin(), nums.end());
    int n = nums.size();
    int i, j;
    for (i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
            break;
    }

    if (i < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (j = n - 1; j >= 0; j--)
        {
            if (nums[i] < nums[j])
                break;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
}