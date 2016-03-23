class Solution {

private:
	vector<int> genNext(const string& needle)
	{
		int i = 0, j = 1;
		int len = 0;
		vector<int> next(needle.size());
		next[0] = 0;
		for (; j < needle.size(); j++)
		{
			if (needle[i] == needle[j])
			{
				len++;
				next[j] = len;
				i++;
			}
			else
			{
				len = 0;
				i = 0;
			}
		}
		return next;
	}

public:

	int strStr(string s1, string s2) 
	{
        int length1 = s1.size(),length2 = s2.size();
        if (length2==0) return 0;
        if (length1 < length2) return -1;
        
        vector<int> next = genNext(s2);
        
        for (int i = 0, q= 0; i < length1;i++) 
        {
            while (q > 0 && s1[i] != s2[q]) 
                q = next[q-1];  
            if (s1[i] == s2[q]) 
                q++;
            if (q == length2) 
                return i-q+1;
        }
        return -1;
	}
};