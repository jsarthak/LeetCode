// Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

// A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

// Return the maximum length of a subarray with positive product.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int m = 0, n = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                m = 0;
                n = 0;
            }
            else
            {
                m++;
                n++;
                if (nums[i] < 0)
                {
                    swap(m, n);
                    if (m == n)
                    {
                        m = 0;
                    }
                }
            }
            ans = max(ans, m);
        }
        return ans;
    }
};