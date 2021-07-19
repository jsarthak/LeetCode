
#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    int start = 0;
    int best = 1;
    int j, k;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        j = i - 1;
        k = i + 1;
        len = 1;
        while (j >= 0 && k < n && s[j] == s[k])
        {
            j--;
            k++;
            len += 2;
        }
        if (len > best)
        {
            best = len;
            start = j + 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            j = i - 2;
            k = i + 1;
            len = 2;
            while (j >= 0 && k < n && s[j] == s[k])
            {
                j--;
                k++;
                len += 2;
            }
            if (len > best)
            {
                best = len;
                start = j + 1;
            }
        }
    }
    return s.substr(start, best);
}

int main()
{
    string s;
    cin >> s;
    string c = longestPalindrome(s);
    cout << c << "\n";
    return 0;
}