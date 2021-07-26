// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, const int &k, int target)
    {
        if (target == 0 && temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        int last = 0;
        if (temp.size() > 0)
            last = temp.back();
        for (int i = last + 1; i <= 9; i++)
        {
            temp.push_back(i);
            backtrack(ans, temp, k, target - i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, temp, k, n);
        return ans;
    }
};