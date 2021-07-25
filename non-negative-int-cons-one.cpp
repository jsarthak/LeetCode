// Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.

// Input: n = 5
// Output: 5
// Explanation:
// Here are the non-negative integers <= 5 with their corresponding binary representations:
// 0 : 0
// 1 : 1
// 2 : 10
// 3 : 11
// 4 : 100
// 5 : 101
// Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findIntegers(int n)
    {
        vector<int> dp(32);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < 32; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int ans = 0;
        int prev = 0;
        for (int i = 30; i >= 0; i--)
        {
            if (n & (1 << i))
            {
                ans += dp[i];
                if (prev)
                {
                    --ans;
                    break;
                }
                prev = 1;
            }
            else
            {
                prev = 0;
            }
        }
        return ans + 1;
    }
};