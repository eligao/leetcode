class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        
        int w=1,r=1;    //two pointers. r reads elems, w puts elems. 
        
        
        while(r<nums.size())
        {
            if(nums[r]==nums[r-1])
                r++;
            else
            {
                nums[w]=nums[r];
                r++;w++;
            }
        }
        
        return w;
    }
};

/*
    11234445
    
*/