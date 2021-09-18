
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0;
    int j = n - 1;

    while (i < m && j >= 0 && matrix[i][j] != target)
    {
        if (target > matrix[i][j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    if (i < m && j >= 0)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target;
    cin >> target;
    cout << searchMatrix(matrix, target);
    return 0;
}