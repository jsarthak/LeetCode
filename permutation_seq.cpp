// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i <= n; i++)
        {
            fact = fact * i;
            numbers.push_back(fact);
        }
        vector<int> m;
        for (int i = 0; i <= n; i++)
        {
            m.push_back(i);
        }
        string ans = "";

        for (int i = n - 1; i > 0; i--)
        {
            int tmp = (k - 1) / numbers[i - 1];
            k = k - tmp * numbers[i - 1];
            ans += to_string(m[tmp + 1]);
            m.erase(m.begin() + tmp + 1);
        }
        ans += to_string(m[1]);
        return ans;
    }
    //         For n = 3;
    //         the numbers list nums = {1,2,3};
    //         fact =  (n-1)! = 2;
    //         we need to find k-1 indexed so decrement k
    //         the first digit will be at k/fact;
    //             -> k = 2, fact = 2 => index = 1;
    //             -> append ans + 2;
    //             -> erase 2;
    //             -> now nums = {1, 3};
    //         k = k%fact => 2%2 = 0;
    //         fact = fact/nums.size = 2/2 = 1;
    //             -> now index = 0/1 = 0;
    //             -> add 1 to ans;
    //             -> now ans = 21
    //             -> erase 1
    //             -> nums={3}
    //         if nums size == 0 break the loop
    // second
    // vector<int> nums;
    //     for(int i = 1; i <= n; i++){
    //         nums.push_back(i);
    //     }
    //     int fact=1;
    //     for (int i = 1; i <n;i++){
    //         fact = fact*i;
    //     }
    //     k--;
    //     string ans ="";
    //     while(1){
    //         ans += to_string(nums[k/fact]);
    //         nums.erase(nums.begin()+k/fact);
    //         if (nums.size()==0) break;
    //         k = k%fact;
    //         fact = fact/nums.size();
    //     }
    //     return ans;
};