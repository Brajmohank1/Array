/*

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 


*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 =-1 , ele2 = -1 , count1 = 0 , count2 = 0;
              int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == ele1) count1++;
            else if(nums[i] == ele2) count2++;
            else if(count1 == 0) {
                ele1 = nums[i];
                count1++;
            }
             else if(count2 == 0) {
                ele2 = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
            
        }
        
        
        count1 = 0 , count2 = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == ele1) count1++;
            else if(nums[i] == ele2) count2++;
        }
        
   
        vector<int> res;
        if(count1 > n/3)
            res.push_back(ele1);
        if(count2 > n/3)
            res.push_back(ele2);
    
    
    return res;
    }
};
