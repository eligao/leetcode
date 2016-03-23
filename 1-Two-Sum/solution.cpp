class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mymap; //a reverse mapping of nums
		vector<int> ret_val;
		const unsigned n = nums.size();
		for (unsigned i = 0; i<n; i++)
		{
			mymap[nums[i]] = i;
		}
		for (unsigned i = 0; i<n; i++)
		{
			int diff = target - nums[i];
			unordered_map<int,int>::iterator it = mymap.find(diff);
			if (it != mymap.end()) //if found the  
			{
				if (i>=it->second)
				{
					continue;
				}
				ret_val.push_back(i);
				ret_val.push_back(it->second);
				return ret_val;
			}
		}
	}
};