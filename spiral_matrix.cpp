#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    int dir = 0;
    vector<int> ans;
    while (top <= bottom && left <= right)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            dir = 1;
            top++;
        }
        else if (dir == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            dir = 2;
            right--;
        }
        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            dir = 3;
            bottom--;
        }
        else if (dir == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            dir = 0;
            left++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    vector<int> ans = spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}