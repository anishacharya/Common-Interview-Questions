/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* current=head;
        ListNode* next;
        while(current->next!=NULL)
        {
            if(current->val==current->next->val)
            {
                next=current->next->next;
                delete(current->next);
                current->next=next;
            }
            else
                current=current->next;
        }
        return head;
    }
    
};
