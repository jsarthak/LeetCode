#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n));
    int top = 0;
    int bottom = ans.size() - 1;
    int left = 0;
    int right = ans.size() - 1;
    int dir = 0;
    int j = 1;

    while (top <= bottom && left <= right)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
            {
                ans[top][i] = j++;
            }
            dir = 1;
            top++;
        }
        else if (dir == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                ans[i][right] = j++;
            }
            dir = 2;
            right--;
        }
        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
            {
                ans[bottom][i] = j++;
            }
            dir = 3;
            bottom--;
        }
        else if (dir == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans[i][left] = j++;
            }
            dir = 0;
            left++;
        }
    }
    return ans;
}
