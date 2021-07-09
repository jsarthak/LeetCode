#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums){

	// find the size of the array
	int n = nums.size();

	// if array contains a signle element return it
	if (n == 1) return nums[0];

	// variables intitialization
	int minP = nums[0];
	int maxP = nums[0];
	int ans = nums[0];

	// loop through each number in the array
	for (int i = 1; i < n; i++){
		
		// if a number is negative then swap min and max
		if (nums[i] < 0){
			int temp = minP;
			minP = maxP;
			maxP = temp;
		}

		// calculate new min and max
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