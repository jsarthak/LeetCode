
// There are n oranges in the kitchen and you decided to eat some of these oranges every day as follows:

// Eat one orange.
// If the number of remaining oranges (n) is divisible by 2 then you can eat  n/2 oranges.
// If the number of remaining oranges (n) is divisible by 3 then you can eat  2*(n/3) oranges.
// You can only choose one of the actions per day.

// Return the minimum number of days to eat n oranges.

#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> dp;
int dfs(int n)
{
    if (dp.count(n))
        return dp[n];
    int a1 = 1 + (n % 2) + minDays(n / 2);
    int a2 = 1 + (n % 3) + minDays(n / 3);
    dp[n] = min(a1, a2);
    return dp[n];
}
int minDays(int n)
{
    dp[0] = 0;
    dp[1] = 1;
    return dfs(n);
}
int main()
{
    int x;
    cin >> x;
    int ans = minDays(x);
    cout << ans << "\n";
    return 0;
}