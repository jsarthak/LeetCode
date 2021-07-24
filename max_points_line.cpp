

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ans = 1;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<float, int> m;
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < points.size(); j++)
            {
                float x = x1 - points[j][0];
                float y = y1 - points[j][1];
                if (x == 0)
                {
                    m[INT_MAX]++;
                }
                else
                {
                    m[y / x]++;
                }
            }
            for (auto it : m)
            {
                ans = max(ans, it.second + 1);
            }
        }
        return ans;
    }
};