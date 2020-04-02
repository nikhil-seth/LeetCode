//148. Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *merge(ListNode *a,ListNode *b){
    if(!a)
        return b;
    if(!b)
        return a;
    if(a->val<b->val){
        a->next=merge(a->next,b);
        return a;
    }
    else{
        b->next=merge(a,b->next);
        return b;
    }
}
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *s,*f;
        s=f=head;
        f=f->next;
        while(s && f && f->next){
            s=s->next;
            f=f->next->next;
        }
        f=s->next;
        s->next=nullptr;
        head=sortList(head);
        f=sortList(f);
        head=merge(head,f);
        return head;
    }
};