// We have a two dimensional matrix grid where each value is 0 or 1.

// A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

// After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

// Return the highest possible score.

#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = !a[i];
    }
}
int matrixScore(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        if (grid[i][0] == 0)
            reverse(grid[i]);
    }

    for (int i = 1; i < c; i++)
    {
        int cnt = 0;
        for (int j = 0; j < r; j++)
        {
            cnt += grid[j][i];
        }
        if (cnt < (r + 1) / 2)
        {
            for (int j = 0; j < r; j++)
            {
                grid[j][i] = !grid[j][i];
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans += grid[i][j] * pow(2, c - 1 - j);
        }
    }
    return ans;
}
