#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    if (nums.size() < 2)
        return false;
    vector<int> pref(nums.size() + 1, 0);
    pref[0] = nums[0];
    for (int i = 1; i <= nums.size(); i++)
    {
        pref[i] = pref[i - 1] + nums[i - 1];
        if (i < nums.size() && nums[i - 1] == 0 && nums[i] == 0)
            return true;
    }

    for (int i = 2; i <= nums.size(); i++)
    {
        if (pref[i] - pref[0] < k)
            continue;
        for (int j = 0; j < i - 1; j++)
        {
            if ((pref[i] - pref[j]) % k == 0)
                return true;
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    cout << checkSubarraySum(nums, k);

    return 0;
}