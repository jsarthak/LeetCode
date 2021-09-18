
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<int> col;
    set<int> posDiag;
    set<int> negDiag;

    void solve(vector<vector<string>> &ans, vector<vector<char>> &temp, int n, int row)
    {
        if (row == n)
        {
            string x;
            vector<string> sol;
            for (auto it : temp)
            {
                x = "";
                for (char ch : it)
                {
                    x.push_back(ch);
                }
                sol.push_back(x);
            }
            ans.push_back(sol);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (col.count(i) || posDiag.count(i + row) || negDiag.count(row - i))
            {
                continue;
            }
            col.insert(i);
            posDiag.insert(i + row);
            negDiag.insert(row - i);
            temp[row][i] = 'Q';
            solve(ans, temp, n, row + 1);
            col.erase(i);
            posDiag.erase(i + row);
            negDiag.erase(row - i);
            temp[row][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<char>> temp(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(ans, temp, n, 0);
        return ans;
    }
};