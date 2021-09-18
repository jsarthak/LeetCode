#include <bits/stdc++.h>
using namespace std;

const vector<pair<char, int>> lookup = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int getRank(char c)
{
	for (int i = 0; i < lookup.size(); i++)
	{
		if (c == lookup[i].first)
		{
			return lookup[i].second;
		}
	}
	return -1;
}

int romanToInt(string s)
{
	int number = 0;
	int i = 0;
	while (i < s.size())
	{
		int rank = getRank(s[i]);
		int rank1 = getRank(s[i + 1]);
		if (rank < rank1)
		{
			number -= rank;
		}
		else
		{
			number += rank;
		}
		i++;
	}
	return number;
}

int main()
{
	string roman;
	cin >> roman;

	cout << romanToInt(roman);

	return 1;
}