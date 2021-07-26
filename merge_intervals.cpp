// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
            return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for (auto interval : intervals)
        {
            if (interval[0] <= temp[1])
            {
                temp[1] = max(interval[1], temp[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = interval;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};