
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> left(height.size()), right(height.size());
        int maxL = 0, maxR = 0;
        for (int i = 0; i < height.size(); i++)
        {
            maxL = max(maxL, height[i]);
            left[i] = maxL;
        }
        for (int i = height.size() - 1; i >= 0; i--)
        {
            maxR = max(maxR, height[i]);
            right[i] = maxR;
        }

        int ans = 0;
        for (int i = 0; i < height.size(); i++)
        {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};