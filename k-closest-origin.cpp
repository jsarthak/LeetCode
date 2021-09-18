

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<pair<int, int>> vals;
        for (int i = 0; i < points.size(); i++)
        {
            int distance = (pow(0 - points[i][0], 2) + pow(0 - points[i][1], 2));
            vals.push_back({distance, i});
        }
        sort(vals.begin(), vals.end());

        vector<vector<int>> ans;
        int i = 0;
        for (auto it : vals)
        {
            if (i < k)
            {
                ans.push_back(points[it.second]);
            }
            i++;
        }
        return ans;
    }
};