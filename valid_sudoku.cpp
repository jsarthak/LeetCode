// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<set<int>> row(9), col(9), box(9);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                    continue;
                else
                {
                    int grid = (i / 3) * 3 + j / 3;

                    if (row[i].find(board[i][j]) != row[i].end() ||
                        col[j].find(board[i][j]) != col[j].end() ||
                        box[grid].find(board[i][j]) != box[grid].end())
                    {
                        return false;
                    }
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    box[grid].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};