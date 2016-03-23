class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> > q;
        //priority_queue<int> q;
        for(auto val:nums)
        {
 
            if(q.size()<k)
            {
                q.push(val);
                continue;
            }
            else
            {
                q.push(val);
                q.pop();
            }
        }
        return q.top();
    }
};