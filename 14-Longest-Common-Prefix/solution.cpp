class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        string lcp("");
        if(strs.size()==0)  return lcp;
        int min_strlen=INT_MAX;
        
        for(auto& str:strs)
        {
            min_strlen=str.size()<min_strlen?str.size():min_strlen;
        }
        
        char ch;
        while(lcp.size()<min_strlen)
        {
            for(int i=0;i<strs.size();i++)
            {
                const string& str=strs[i];
                if(i==0) 
                    ch=str[lcp.size()];
                else
                {
                    if(ch!=str[lcp.size()])
                        return lcp;     
                }
            }
            lcp.push_back(ch);
        }
        return lcp;
    }
};