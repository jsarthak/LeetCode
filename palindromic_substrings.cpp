// Total palindromic substrings in a string

#include <bits/stdc++.h>
using namespace std;

// Older Approach
// bool isPalindrome(string x)
// {
//     string y = x;
//     reverse(y.begin(), y.end());
//     return x == y;
// }

// int countSubstrings(string s)
// {
//     int ans = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         for (int j = i; j < s.size(); j++)
//         {
//             string x = s.substr(i, j - i + 1);
//             if (isPalindrome(x))
//                 ans++;
//         }
//     }
//     return ans;
// }

int countSubstrings(string s)
{
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i;
        int cnt = 0;
        // For odd mids
        while (l >= 0 && r < n && s[l] == s[r])
        {
            l--;
            r++;
            cnt++;
        }
        ans += cnt;
        cnt = 0;
        // For evens
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            l--;
            r++;
            cnt++;
        }
        ans += cnt;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int c = countSubstrings(s);
    cout << c << "\n";
    return 0;
}