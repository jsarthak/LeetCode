// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int n)
    {
        vector<int> ans;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
        }

        return dp[n];
    }
};