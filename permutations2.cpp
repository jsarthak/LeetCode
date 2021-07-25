// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, set<vector<int>> &col, unordered_map<int, int> &freq, const vector<int> &nums)
    {
        if (temp.size() == nums.size())
        {
            ans.push_back(temp);
            col.insert(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (freq[nums[i]] > 0)
            {
                freq[nums[i]]--;
                temp.push_back(nums[i]);
                if (col.count(temp) == 0)
                {
                    col.insert(temp);
                    backtrack(ans, temp, col, freq, nums);
                }
                temp.pop_back();
                freq[nums[i]]++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> col;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for (int a : nums)
        {
            freq[a]++;
        }
        backtrack(ans, temp, col, freq, nums);
        return ans;
    }
};