#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
	int n = nums.size();
	if (n < 3){
		return {};
	}
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	int i, j, k, sum;
	for (i = 0; i < n -2; i++){
		if (i > 0 && nums[i] == nums[i-1]){
			continue;
		}
		j = i + 1;
		k = n - 1;
		while (j < k){
			sum = nums[i] + nums[j] + nums[k];
			if (sum < 0){
				j++;
			} else if (sum>0) {
				k--;
			} else {
				ans.push_back({nums[i], nums[j],nums[k]});
				while (j<k && nums[j] == nums[j+1]) j++;
				while (j<k && nums[k] == nums[k-1]) k--;
				j++;
				k--;
			}
		}
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<int> nums;
	while( n--){
		int a;
		cin >> a;
		nums.push_back(a);
	}

	vector<vector<int>> sums = threeSum(nums);
	cout << '[';
	for (int i = 0 ; i < sums.size();i++){
		cout << '[';
		for (int j = 0; j < sums[i].size(); j++){
		  cout << sums[i][j] << " " ; 
		}
		cout << ']' << " ";
	}
	cout << ']' << endl;
	return 1;
}