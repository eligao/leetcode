/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 
class Solution {
    
    
private:

    unordered_map<int, vector<int>::iterator> hash_val2pos;
    
    TreeNode* buildTreeRecur(
            const vector<int>::iterator &preorder_begin,
            const vector<int>::iterator &inorder_begin,
            size_t order_size
            )
    {
        if(order_size==0)
            return NULL;
        int val=*preorder_begin;
        TreeNode* root=new TreeNode(val);
        //auto inorder_mid=find(inorder_begin, inorder_begin+order_size, val);
        auto inorder_mid=hash_val2pos[val];
        size_t left_size=inorder_mid-inorder_begin;
        size_t right_size=order_size-left_size-1;
        root->left=buildTreeRecur(preorder_begin+1,inorder_begin,left_size);
        root->right=buildTreeRecur(preorder_begin+1+left_size,inorder_begin+left_size+1,right_size);
        return root;
    }
        
    
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(auto it=inorder.begin();it!=inorder.end();it++)
        {
            hash_val2pos[*it]=it;
        }
        return buildTreeRecur(preorder.begin(),inorder.begin(),preorder.size());
    }
};