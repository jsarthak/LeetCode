//Given a string s, find the length of the longest substring without repeating characters.
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
	int n = s.size();
	int len = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		len = 0;
		vector<int> freq(128, 0);
		for (int j = i; j < n; j++)
		{
			if (freq[s[j]] == 0)
			{
				len++;
				freq[s[j]]++;
			}
			else
			{
				break;
			}
		}
		ans = max(len, ans);
	}
	return ans;
}

int main()
{
	string s;
	cin >> s;
	cout << lengthOfLongestSubstring(s);

	return 1;
}