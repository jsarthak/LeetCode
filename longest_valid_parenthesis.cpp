#include <bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s)
{
    if (s.size() == 0)
        return 0;
    int ans;
    stack<int> dump;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            if (!dump.empty())
            {
                dump.pop();
            }
            if (!dump.empty())
            {
                ans = max(ans, i - dump.top());
            }
            else
            {
                dump.push(i);
            }
        }
        else
        {
            dump.push(i);
        }
    }
}
int main()
{

    return 0;
}