//86. Partition List

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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
            return head;
        ListNode *h1,*h2,*ptr1,*ptr2;
        h1=h2=ptr1=ptr2=nullptr;
        while(head){
            if(head->val<x){
                if(ptr1){
                    ptr1->next=head;
                    ptr1=ptr1->next;
                }
                else
                    ptr1=h1=head;
            }
            else{
                if(ptr2){
                    ptr2->next=head;
                    ptr2=ptr2->next;
                }
                else
                    ptr2=h2=head;
            }
            head=head->next;
        }
        if(h1){
            head=h1;
            ptr1->next=h2;
            if(ptr2)
                ptr2->next=nullptr;
        }
        else
            return h2;
        return head;
    }
};