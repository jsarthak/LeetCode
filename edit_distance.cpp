// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{

    int N = word1.size();
    int M = word2.size();

    if (M == 0)
        return N;
    if (N == 0)
        return M;
    if (M == 0 && N == 0)
        return 1;

    vector<vector<int>> distance(N + 1, vector<int>(M + 1, 1));
    for (int i = 0; i < N; i++)
    {
        distance[i][0] = i;
    }

    for (int j = 0; j < M; j++)
    {
        distance[0][j] = j;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                distance[i][j] = distance[i - 1][j - 1];
            }
            else
            {
                distance[i][j] = min({distance[i - 1][j - 1], distance[i - 1][j], distance[i][j - 1]}) + 1;
            }
        }
    }
    return distance[N][M];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int x = minDistance(s1, s2);
    cout << x << "\n";
    return 0;
}