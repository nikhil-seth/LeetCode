//141. Linked List Cycle

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
    bool hasCycle(ListNode *head){
        ListNode *fast,*slow;
        fast=slow=head;
        while(fast && fast->next){
            fast=fast->next;
            if(fast==slow)
                return 1;
            if(fast->next){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return 0;
    }
};