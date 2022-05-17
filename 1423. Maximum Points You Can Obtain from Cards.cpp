/*

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 

*/

class Solution {
public:
   
    int maxScore(vector<int>& cardPoints, int k) {
        int n =  cardPoints.size();
        
        vector<int> sumLeft(n,0) ,sumRight(n , 0);
        sumLeft[0] = cardPoints[0],sumRight[n-1]=cardPoints[n-1];
        int j = n - 1;
        for(int i = 1 ; i < j ; i++)
        {
            sumLeft[i] = sumLeft[i-1] + cardPoints[i];
            sumRight[j - i] = sumRight[j - i + 1] + cardPoints[j - i] ;
        
        
        } 
        
        sumLeft[j] = sumLeft[j -1] + cardPoints[j];
        sumRight[0] = sumRight[1] + cardPoints[0];
         
       
      
        int ans = 0;
            for(int i = 0 ; i < k - 1; i++){
                int ansFirst = sumLeft[i];
                int ansLast = sumRight[n - k +i  + 1];
                 
                ans = max(ans ,ansFirst + ansLast);
            }
        
      
        ans = max(ans , sumLeft[k - 1] ) ;
        ans =max(ans ,sumRight[n-k]);
        return ans;
    }
};
