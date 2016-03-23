class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //deque<int> subarr;
        int subarr_size=INT_MAX;
        int i1=0, i2=0;  //[i1,i2) as the current subarr within nums;
        int nums_size=nums.size();
        int sum=0;
        int i_size; //current subarray size in this iteration
        
        while(true)
        {
            i_size=i2-i1;

            if(sum<s)
            {
                if(i2==nums_size) break; 
                sum+=nums[i2];
                i2++;
            }
            else if(sum>=s)
            {
                if(subarr_size>i_size)
                    subarr_size=i_size;
                if (i_size==1)  //step forward
                {
                    if (i2==nums_size) break;
                    sum=nums[i2];
                    i1++;
                    i2++;
                }
                else
                {
                    sum-=nums[i1];
                    i1++;
                }
            }
        }
        
        if(subarr_size==INT_MAX)
            subarr_size=0;
        return subarr_size;
    }
};