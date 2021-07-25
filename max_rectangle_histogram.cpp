// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Init var ans = 0 -> for keeping max area
// use a stack<pair<int, int>> for keeping the index and height
// if currheight > stack's top height then pop stack and calculate area
// otherwise push to the stack current index and height
// do this untill stack is empty
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int ans = 0;
    stack<pair<int, int>> dump;
    int n = heights.size();
    for (int i = 0; i < n; i++)
    {
        int start = i;
        int height = heights[i];
        while (!dump.empty() && dump.top().second > height)
        {
            int h = dump.top().second;
            int w = dump.top().first;
            dump.pop();
            ans = max(ans, h * (i - w));
            start = w;
        }
        dump.push({start, height});
    }

    while (!dump.empty())
    {
        int h = dump.top().second;
        int w = dump.top().first;
        ans = max(ans, (h * (n - w)));
        dump.pop();
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    cout << largestRectangleArea(nums);

    return 1;
}