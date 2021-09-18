

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> permute(vector<int> &nums)
// {
//     vector<vector<int>> ans;
//     if (nums.size() == 1)
//         ans.push_back({nums[0]});
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int num = nums[i];
//         vector<int> temp;
//         for (int j = 0; j < nums.size(); j++)
//         {
//             if (i != j)
//                 temp.push_back(nums[j]);
//         }
//         vector<vector<int>> tempAns = permute(temp);

//         for (int k = 0; k < tempAns.size(); k++)
//         {
//             vector<int> currAns = tempAns[k];
//             currAns.insert(currAns.begin(), num);
//             ans.push_back(currAns);
//         }
//     }
//     return ans;
// }

// Faster version

void backtrack(vector<vector<int>> &result, vector<int> &nums, vector<int> &curr)
{
    if (curr.size() == nums.size())
    {
        result.push_back(curr);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (count(curr.begin(), curr.end(), nums[i]) == 1)
            continue;
        curr.push_back(nums[i]);
        backtrack(result, nums, curr);
        curr.pop_back();
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> curr;
    backtrack(result, nums, curr);
    return result;
}

int main()
{
}