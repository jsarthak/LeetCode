// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<bool>> &visited, int i, int j, int pos, const vector<vector<char>> &board, bool &ans, const string &word)
    {

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;

        if (visited[i][j] || ans || board[i][j] != word[pos])
            return;

        if (pos == word.size() - 1)
        {
            ans = true;
            return;
        }

        visited[i][j] = true;
        backtrack(visited, i + 1, j, pos + 1, board, ans, word);
        backtrack(visited, i - 1, j, pos + 1, board, ans, word);
        backtrack(visited, i, j + 1, pos + 1, board, ans, word);
        backtrack(visited, i, j - 1, pos + 1, board, ans, word);
        visited[i][j] = false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool ans = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                backtrack(visited, i, j, 0, board, ans, word);
            }
        }
        return ans;
    }
};