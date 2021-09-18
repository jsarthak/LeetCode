// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int start, const vector<int> &candidates, vector<vector<int>> &ans, vector<int> &curr, int target)
    {
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }
        if (target < 0)
            return;
        int prev = -1;
        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates[i] == prev)
                continue;
            curr.push_back(candidates[i]);
            solve(i + 1, candidates, ans, curr, target - candidates[i]);
            curr.pop_back();
            prev = candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, ans, temp, target);
        return ans;
    }
};