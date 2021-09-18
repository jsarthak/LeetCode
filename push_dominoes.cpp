// There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

// After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

// When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

// For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

// You are given a string dominoes representing the initial state where:

// dominoes[i] = 'L', if the ith domino has been pushed to the left,
// dominoes[i] = 'R', if the ith domino has been pushed to the right, and
// dominoes[i] = '.', if the ith domino has not been pushed.
// Return a string representing the final state.

// Input: dominoes = ".L.R...LR..L.."
// Output: "LL.RR.LLRRLL.."

#include <bits/stdc++.h>
using namespace std;

string pushDominoes(string d)
{

    int n = d.size();
    vector<int> forces(n, 0);

    int force = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i] == 'R')
            force = n;
        else if (d[i] == 'L')
            force = 0;
        else
            force = max(force - 1, 0);
        forces[i] += force;
    }
    force = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (d[i] == 'L')
            force = n;
        else if (d[i] == 'R')
            force = 0;
        else
            force = max(force - 1, 0);
        forces[i] -= force;
    }

    string ans = "";
    for (int f : forces)
    {
        if (f > 0)
            ans.push_back('R');
        else if (f < 0)
            ans.push_back('L');
        else
            ans.push_back('.');
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    string ans = pushDominoes(s);
    cout << ans << "\n";
    return 0;
}