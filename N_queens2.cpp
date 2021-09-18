// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_set<int> col;
    unordered_set<int> pos;
    unordered_set<int> neg;

    void solve(int &ans, vector<vector<char>> &temp, int n, int row)
    {
        if (row == n)
        {
            ans++;
        }

        for (int c = 0; c < n; c++)
        {
            if (
                col.find(c) != col.end() ||
                pos.find(c + row) != pos.end() ||
                neg.find(row - c) != neg.end())
                continue;
            col.insert(c);
            pos.insert(row + c);
            neg.insert(row - c);
            temp[row][c] = 'Q';
            solve(ans, temp, n, row + 1);
            col.erase(c);
            pos.erase(row + c);
            neg.erase(row - c);
            temp[row][c] = '.';
        }
    }

    int totalNQueens(int n)
    {
        vector<vector<char>> temp(n, vector<char>(n, '.'));
        int res = 0;
        solve(res, temp, n, 0);
        return res;
    }
};