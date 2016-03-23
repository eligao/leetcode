/*
    592764823756817
    1212
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        vector<int> dp(nums.size(),1);
        int dp_max=1;
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            dp_max=max(dp_max,dp[i]);
        }
        return dp_max;
    }
};