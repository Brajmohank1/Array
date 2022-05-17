/*

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 



*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0 ; i < n - 2 ; i++){
            
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])){
                
                int index2 = i + 1 , index3 = n-1;
                int sum = 0 - nums[i];
                
                cout<<sum << " "<< nums[i];
                while(index2 < index3){
                   
                    if(nums[index2] + nums[index3] == sum){
                        res.push_back({nums[i] , nums[index2] , nums[index3]});
                          while(index2 < index3 && nums[index2] == nums[index2 + 1]) index2++;
                    
                    while(index3 > index2 && nums[index3] == nums[index3 - 1])index3--;
                    
                    index2++;
                        index3--;
                    }
                    
                   
                   else if(nums[index2] + nums[index3]< sum)
                        index2++;
                    else  
                        index3--;
                    
                }
                
            }
            
        }
        return res;
        
    }
};
