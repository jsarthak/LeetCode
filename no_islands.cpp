// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// nput: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(int i, int j, int row, int col)
    {
        if (i >= 0 && i < row && j >= 0 && j < col)
            return true;
        return false;
    }

    void bfs(const vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j, int m, int n)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            visited[i][j] = 1;
            // right
            if (isValid(i, j + 1, m, n) && !visited[i][j + 1] && grid[i][j + 1] == '1')
            {
                q.push({i, j + 1});
                visited[i][j + 1] = 1;
            }
            // down
            if (isValid(i + 1, j, m, n) && !visited[i + 1][j] && grid[i + 1][j] == '1')
            {
                q.push({i + 1, j});
                visited[i + 1][j] = 1;
            }
            // left
            if (isValid(i, j - 1, m, n) && !visited[i][j - 1] && grid[i][j - 1] == '1')
            {
                q.push({i, j - 1});
                visited[i][j - 1] = 1;
            }
            // top
            if (isValid(i - 1, j, m, n) && !visited[i - 1][j] && grid[i - 1][j] == '1')
            {
                q.push({i - 1, j});
                visited[i - 1][j] = 1;
            }
        }
        return;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    bfs(grid, visited, i, j, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};