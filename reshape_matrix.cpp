#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    int n = mat.size(), m = mat[0].size();
    if (m * n != r * c)
        return mat;
    vector<vector<int>> ans;
    vector<int> temp;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp.push_back(mat[i][j]);
            x++;
            if (x == c)
            {
                ans.push_back(temp);
                temp.clear();
                x = 0;
            }
        }
    }
    return ans;
}