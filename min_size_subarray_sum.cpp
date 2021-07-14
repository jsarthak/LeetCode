// Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
    int ans = INT_MAX;
    int i = 0;
    int j = i;
    int sum = 0;
    while (j < nums.size())
    {
        sum += nums[j];
        while (sum >= target)
        {
            sum -= nums[i];
            ans = min(ans, j - i + 1);
            i++;
        }
        j++;
    }
    return ans == INT_MAX ? 0 : ans;
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << minSubArrayLen(target, nums);
    return 0;
}