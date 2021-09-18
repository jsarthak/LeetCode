//Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.

#include <bits/stdc++.h>
using namespace std;

int findComplement(int num)
{
    for (int i = 0; i <= log2(num); i++)
    {
        num = num ^ (1 << i);
    }
    return num;
}

int main()
{
    int num;
    cin >> num;
    int cmp = findComplement(num);
    cout << cmp;
    return 0;
}