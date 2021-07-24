// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int ans = 0;
    unordered_map<int, int> prefSums;
    prefSums[0] = 1;
    int currSum = 0;
    for (int i : nums)
    {
        currSum += i;
        int delta = currSum - k;
        ans += prefSums[delta];
        prefSums[currSum]++;
    }
    return ans;
}

int main()
{
    return 0;
}