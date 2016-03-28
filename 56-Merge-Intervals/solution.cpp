/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool IntervalComp(const Interval& lhs, const Interval& rhs)
{
    return lhs.start<rhs.start;
} 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret_val;
        sort(intervals.begin(),intervals.end(),IntervalComp);
        int start,end;
        
        for(auto iv:intervals)
        {
            if(ret_val.empty()||ret_val.back().end<iv.start)
                ret_val.push_back(iv);
            else
                ret_val.back().end=max(ret_val.back().end,iv.end);
        }
        
        return ret_val;
    }
};