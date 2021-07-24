
// Given an array nums, partition it into two (contiguous) subarrays left and right so that:

// Every element in left is less than or equal to every element in right.
// left and right are non-empty.
// left has the smallest possible size.
// Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

// To solve this, we will follow these steps −

// n := size of A, create an array mx of size n
// minVal := last element of A
// mx[0] := A[0]
// for i in range 1 to n – 1
// mx[i] := max of A[i] and A[i – 1]
// ans := size of A – 1
// for i in range n – 1 down to 1
// minVal := minimum of minVal and A[i]
// if minVal >= mx[i – 1], then ans := i
// return ans

#include <bits/stdc++.h>
using namespace std;

int partitionDisjoint(vector<int> &a)
{
    int n = a.size();
    vector<int> b(n);
    int minVal = a[n - 1];
    b[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        b[i] = max(a[i], b[i - 1]);
    }
    int ans = n - 1;
    for (int i = n - 1; i >= 1; i--)
    {
        minVal = min(minVal, a[i]);
        if (minVal >= b[i - 1])
            ans = i;
    }
    return ans;
}