// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> ans;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = 1;
        ans.push_back({1});
        for (int i = 1; i < n; i++)
        {
            vector<int> row;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
                if (dp[i][j] != 0)
                {
                    row.push_back(dp[i][j]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> generate(int n) {
//         vector<vector<int>> dp (n, vector<int> (n,0));
//         dp[0][0] = 1;
//         dp[0].resize(1);
//             for (int i =1;i < n;i++){

//             for (int j = 0; j <= i;j++){
//                 if (j==0 || j== i) dp[i][j] = 1;
//                 else {
//                     dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
//                 }
//             }
//              dp[i].resize(i+1);
//         }
//         return dp;
//     }
// };