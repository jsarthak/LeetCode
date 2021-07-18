// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> mapka;

    // count the frequency of each element
    for (auto n : nums)
    {
        mapka[n]++;
    }

    // add freq, val to a vector
    vector<pair<int, int>> x;
    for (auto it : mapka)
    {
        x.push_back({it.second, it.first});
    }

    // sort in decreasing order of frequency
    sort(x.rbegin(), x.rend());

    // push first k elements to ans
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(x[i].second);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}