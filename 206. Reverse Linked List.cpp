//206. Reverse Linked List

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
        if(!head)
            return head;
        ListNode *prev,*next;
        prev=nullptr;
        while(head){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
};