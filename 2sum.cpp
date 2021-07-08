#include<bits/stdc++.h>
using namespace std;

vector<int> TwoSum(vector<int>& nums, int target){
	// a variable that will store the complement of the current number
	int complement;
	// map to store the complement and its index
	map<int, int> complements;

	// iterate through each element in nums array
	// find the complement of the number as target - num
	// if the complement in the complements map return the current
	// index and the complement's index
	// else add the current number as key and current index as val
	for(int i = 0; i < nums.size(); i++){
		complement = target - nums[i];
		if (complements.count(complement)){
			return {i, complements[complement]};
		} else {
			complements.insert({nums[i], i});
		}
	}

	// default return -1, -1 if none found
	return {-1, -1};
}

int main(){
	// accept an input equal to nums size
	int n;
	cin >> n;
	// while n add elements to a array
	vector<int> nums;
	while(n--){
		int k;
		cin >> k;
		nums.push_back(k);
	}
	// get the target sum
	int target;
	cin >> target;

	vector<int> ans = TwoSum(nums, target);
	cout << "[" << ans[0] << "," << ans[1] << "]" << endl;

	return 1;
}