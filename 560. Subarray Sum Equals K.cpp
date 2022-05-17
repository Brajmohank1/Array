/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2


*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0 , res = 0;
        mp[sum] = 1;
        for(auto a : nums){
            sum += a;
            int find = sum - k;
            
            if(mp.find(find) != mp.end()){
                res += mp[find];
            }
            mp[sum]++;
        }
        
        return res;
    }
};
