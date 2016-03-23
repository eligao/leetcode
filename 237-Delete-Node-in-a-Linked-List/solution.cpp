/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
    0->1->^
    n
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(true)
        {
            node->val=node->next->val;
            if(node->next->next!=NULL)
                node=node->next;
            else
            {
                delete node->next;
                node->next=NULL;
                return;
            }
        }
    }
};