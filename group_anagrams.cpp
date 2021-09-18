
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mapka;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mapka[temp].push_back(strs[i]);
        }

        for (auto it : mapka)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};