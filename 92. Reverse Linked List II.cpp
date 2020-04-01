//92. Reverse Linked List II

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || m==n)
            return head;
        ListNode *curr,*p1,*n1,*prev,*next;
        p1=nullptr;
        curr=n1=head;
        while(m>1){
            m--;
            p1=curr;
            curr=curr->next;
            n--;
            n1=n1->next;
        }
        while(n>0){
            prev=n1;
            n1=n1->next;
            n--;
        }
        prev->next=nullptr;
        prev=n1;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        if(p1)
            p1->next=prev;
        else
            head=prev;
        return head;
    }
};