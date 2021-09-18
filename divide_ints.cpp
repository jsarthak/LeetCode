#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    if (dividend == 0)
    {
        return 0;
    }
    if (dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    if (divisor == 1)
    {
        return dividend;
    }
    if (divisor == -1)
    {
        return -1 * dividend;
    }

    int sign = ((divisor < 0) ^ (dividend < 0)) ? -1 : 1;
    long long int ans = 0;
    long long int temp = 0;
    long long int N = abs(dividend);
    long long int D = abs(divisor);

    for (int i = 31; i >= 0; i--)
    {
        if (temp + (D << i) <= N)
        {
            temp += (D << i);
            ans = ans | (1 << i);
        }
    }

    return ans * sign;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << divide(a, b);
    return 0;
}