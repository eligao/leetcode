class Solution {
public:
    bool canJump(vector<int>& nums) {
        //greedy
        int n=nums.size();
        int r=0;    //reach
        
        for(int i=0;r<n-1 && i<=r;i++)
        {
            r=max(nums[i]+i,r);
        }
        return r>=nums.size()-1;
    }
};