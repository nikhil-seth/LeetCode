//21. Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return l1;
        if(l1 && !l2)
            return l1;
        if(!l1 && l2)
            return l2;
        ListNode *head,*temp;
        if(l1->val<l2->val){
            temp=head=l1;
            l1=l1->next;
        }
        else{
            temp=head=l2;
            l2=l2->next;
        }
        while(l1 && l2){
            if(l1->val <=l2->val){
                head->next=l1;
                l1=l1->next;
            }
            else{
                head->next=l2;
                l2=l2->next;
            }
            head=head->next;
        }
        head->next=nullptr;
        if(l1)
            head->next=l1;
        while(head->next!=nullptr)
            head=head->next;
        if(l2)
            head->next=l2;
        while(head->next!=nullptr)
            head=head->next;
        return temp;
    }
};