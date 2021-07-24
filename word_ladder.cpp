// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> mp(wordList.begin(), wordList.end());
        int ans = 0;
        if (mp.find(endWord) == mp.end())
            return ans;

        queue<string> q;
        q.push(beginWord);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string curr = q.front();
                q.pop();
                if (curr == endWord)
                {
                    return ans + 1;
                }
                for (int i = 0; i < curr.size(); i++)
                {
                    string temp = curr;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;
                        if (mp.find(temp) != mp.end() && temp != curr)
                        {
                            q.push(temp);
                            mp.erase(temp);
                        }
                    }
                }
            }

            ++ans;
        }
        return 0;
    }
};