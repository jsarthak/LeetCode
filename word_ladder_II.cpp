// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        map<string, int> mp;
        for (string w : wordList)
        {
            mp.insert({w, INT_MAX});
        }
        mp[beginWord] = 0;

        queue<pair<string, vector<string>>> q;
        q.push({beginWord, {beginWord}});
        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            string curr = f.first;
            vector<string> list = f.second;
            if (curr == endWord)
            {
                ans.push_back(list);
                continue;
            }

            for (int i = 0; i < curr.size(); i++)
            {
                string temp = curr;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;
                    if (temp == curr)
                        continue;
                    if (mp.find(temp) == mp.end())
                        continue;
                    if (mp[temp] < (int)list.size())
                        continue;
                    mp[temp] = (int)list.size();
                    list.push_back(temp);
                    q.push({temp, list});
                    list.pop_back();
                }
            }
        }
        return ans;
    }
};