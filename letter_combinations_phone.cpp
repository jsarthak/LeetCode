// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

#include <bits/stdc++.h>
using namespace std;

void solve(const vector<vector<char>> &map, vector<string> &ans, string temp, int idx, string digit)
{
    if (idx == digit.size())
    {
        return ans.push_back(temp);
    }

    int dig = digit[idx] - '2';
    ++idx;
    for (auto c : map[dig])
    {
        solve(map, ans, temp + c, idx, digit);
    }
}

vector<string> letterCombinations(string digits)
{

    if (digits.size() == 0)
    {
        return {};
    }

    const vector<vector<char>> map = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}};

    vector<string> ans;
    solve(map, ans, "", 0, digits);

    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = letterCombinations(s);
    for (string x : ans)
    {
        cout << x << "\n";
    }

    return 0;
}