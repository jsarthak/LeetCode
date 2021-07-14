

#include <bits/stdc++.h>
using namespace std;
void generate(vector<string> &ans, string s, int n, int l, int r)
{
    if (l + r == n)
    {
        ans.push_back(s);
        return;
    }
    if (l < n / 2)
        generate(ans, s + "(", n, l + 1, r);
    if (r < l)
        generate(ans, s + ")", n, l, r + 1);
}
vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    generate(ans, "", 2 * n, 0, 0);
    return ans;
}
