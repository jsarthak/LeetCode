
#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int> &citations)
{
    int low = 0;
    int n = citations.size();
    int high = n - 1;

    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int val = n - mid;
        if (citations[mid] >= val)
        {
            ans = val;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> cit = {0, 1, 3, 5, 6};
    int h = hIndex(cit);
    cout << h;
    return 0;
}