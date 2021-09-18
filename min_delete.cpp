
// A string s is called good if there are no two different characters in s that have the same frequency.

// Given a string s, return the minimum number of characters you need to delete to make s good.

// The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
#include <bits/stdc++.h>
using namespace std;

int minDeletions(string s)
{
    vector<int> v(26);
    for (int i = 0; i < s.size(); i++)
    {
        v[s[i] - 'a']++;
    }

    sort(v.rbegin(), v.rend());
    int f = v[0];
    int ans = 0;

    for (auto x : v)
    {
        if (x > f)
        {
            if (f > 0)
            {
                ans += (x - f);
            }
            else
            {
                ans += x;
            }
        }
        f = min(f - 1, x - 1);
    }

    return ans;
}

int main()
{
    string s1;
    cin >> s1;
    int x = minDeletions(s1);
    cout << x << "\n";
    return 0;
}