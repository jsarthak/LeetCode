// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

// You may return the answer in any order.

// Example 1:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, const int &k, const int &n)
    {
        if (temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        int last = 0;
        if (temp.size() > 0)
            last = temp[temp.size() - 1];
        for (int i = last + 1; i <= n; i++)
        {
            temp.push_back(i);
            solve(ans, temp, k, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(ans, temp, k, n);
        return ans;
    }
};