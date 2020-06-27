// 147. Insertion Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *insertSorted(ListNode *head,ListNode *x){
        if(!head) return x;
        if(head->val>=x->val){
            x->next=head;
            return x;
        }
        ListNode *prev=nullptr,*curr=head;
        while(head && head->val<x->val)
            prev=head,head=head->next;
        prev->next=x;
        x->next=head;
        return curr;
    }
    ListNode* insertionSortList(ListNode* head){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!head) return head;
        ListNode *nh=head,*temp;
        head=head->next;
        nh->next=nullptr;
        while(head){
            temp=head->next;
            nh=insertSorted(nh,head);
            head=temp;
        }
        return nh;
    }
};

        