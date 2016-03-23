class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        vector<int> B;
        
        for(auto &val:A)
        {
            if(val!=elem)
                B.push_back(val);
        }
        
        A=B;
        return A.size();
    }
};