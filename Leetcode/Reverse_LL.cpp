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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* previous=NULL;
        ListNode* current=head;
        ListNode* next;
        
        while(current!=NULL)
        {
            next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }
        
        head=previous;
        
        return head;
        
        
        
    }
};
