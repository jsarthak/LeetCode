// Given n non-negative integers a1, a2, ..., an , 
// where each represents a point at coordinate (i, ai). 
// n vertical lines are drawn such that 
// the two endpoints of the line i is at (i, ai) and (i, 0). 
// Find two lines, which, together with the x-axis forms a container, 
// such that the container contains the most water.


#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height){
	int n = height.size();

	vector<pair<int, int>> pairs;

	for (int i = 0; i < n; i++){
		pairs.push_back({height[i], i});
	}

	sort(pairs.rbegin(), pairs.rend());

	int maxP = INT_MIN;
	int minP = INT_MAX;
	int ans = 0;

	for (int i = 0; i < pairs.size(); i++){
		minP = min(minP, pairs[i].second);
		maxP = max(maxP, pairs[i].second);
		ans = max(ans, (maxP-minP)*pairs[i].first);
	}
	return ans;
}

int main(){

	int n;
	cin >> n;
	vector<int> heights;
	while(n--){
		int c;
		cin >> c;
		heights.push_back(c);
	}

	cout << maxArea(heights);

	return 1;
}

