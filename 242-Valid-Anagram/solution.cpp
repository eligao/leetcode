class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool isAnagram(string s, string t) {
        // write your code here
        if(s.size()!=t.size())
        {
            return false;
        }
        
        map<char,int> s_c2i,t_c2i;
        
        for(int i=0;i<s.size();i++)
        {
            auto it_s=s_c2i.find(s[i]);
            if(it_s==s_c2i.end())
                s_c2i[s[i]]=1;
            else
                s_c2i[s[i]]++;
                
            auto it_t=t_c2i.find(t[i]);
            if(it_t==t_c2i.end())
                t_c2i[t[i]]=1;
            else
                t_c2i[t[i]]++;          
        }
        
        for (auto it:s_c2i)
        {
            if(it.second!=t_c2i[it.first])
                return false;
        }
        
        return true;
    }
};