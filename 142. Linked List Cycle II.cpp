//142. Linked List Cycle II

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast,*slow;
        bool found=0;
        if(!head)
            return head;
        fast=slow=head;
        while(fast && fast->next){
            fast=fast->next;
            if(slow==fast){
                found=1;
                break;
            }
            if(fast->next){
                fast=fast->next;
                slow=slow->next;
            }
        }
        if(found==0)
            return nullptr;
        fast=head;
        slow=slow->next;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};