
// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        vector<vector<int>> ans;
        if (intervals.size() < 2)
            return intervals;
        for (auto interval : intervals)
        {
            if (interval[0] <= prev[1])
            {
                prev[1] = max(interval[1], prev[1]);
            }
            else
            {
                ans.push_back(prev);
                prev = interval;
            }
        }
        ans.push_back(prev);
        return ans;
    }
};