// Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

#include<bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       int ans = 0;
        map<int, int> tSum;
        for(auto i : nums1){
            for (auto j : nums2){
                tSum[i+j]++;
            }
        }
        
        for (auto i : nums3){
            for (auto j : nums4){
                if (tSum.count(0-i-j)){
                    ans+=tSum[0-i-j];
                }
            }
        }
        
        return ans;
        
    }
 

