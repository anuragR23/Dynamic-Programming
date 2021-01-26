/*
  * # Dynamic-Programming
  * Learn Dynamic Programming from scratch
  * -->Leetcode Problem Number 300
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       
        int n=nums.size();
        vector<int>LIS(n,1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&LIS[i]<=LIS[j]){
                    LIS[i]=1+LIS[i];
                }
            }
        }
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(LIS[i]>=max){
                max=LIS[i];
                
            }
        }
        return max;
                        
                    
    }
};
