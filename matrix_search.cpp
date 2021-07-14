/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

*/

#include <bits/stdc++.h>
using namespace std;

bool BinarySearch(vector<int> &row, int target)
{
	int n = row.size();
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		int val = row[mid];
		if (val == target)
		{
			return true;
		}
		else if (val > target)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return false;
}

// More Efficient
bool searchMatrixFaster(vector<vector<int>> &matrix, int target)
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

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		if (BinarySearch(matrix[i], target))
		{
			return true;
		}
	}
	return false;
}

int main()
{

	return 0;
}