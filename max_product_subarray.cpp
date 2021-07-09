#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums){

	int n = nums.size();
	if (n == 1) return nums[0];

	int minP = nums[0];
	int maxP = nums[0];
	int ans = nums[0];

	for (int i = 1; i < n; i++){
		
		if (nums[i] < 0){
			int temp = minP;
			minP = maxP;
			maxP = temp;
		}

		minP = min(nums[i], nums[i]*minP);
		maxP = max(nums[i], nums[i]*maxP);
		ans = max(ans, maxP);
	}
	return ans;

}

int main(){
	int n;
	cin >> n;
	vector<int> nums;
	while(n--){
		int a;
		cin >> a;
		nums.push_back(a);
	}

	cout << maxProduct(nums);

	return 1;

}