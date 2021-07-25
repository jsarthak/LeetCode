// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dfs(int start, int end, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        if (start >= grid.size() || end >= grid[0].size() || start < 0 || end < 0 || grid[start][end] == 0)
            return 1;
        if (visited[start][end])
            return 0;

        visited[start][end] = true;

        int ans = dfs(start + 1, end, grid, visited);
        ans += dfs(start, end + 1, grid, visited);
        ans += dfs(start - 1, end, grid, visited);
        ans += dfs(start, end - 1, grid, visited);
        return ans;
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    return dfs(i, j, grid, visited);
                }
            }
        }
        return 0;
    }
};