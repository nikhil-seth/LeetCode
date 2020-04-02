//143. Reorder List

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
    void reorderList(ListNode* head) {
        ListNode *s,*f,*next;
        if(!head || !head->next)
            return;
        s=f=head;
        f=f->next;
        while(s && f && f->next){
            f=f->next->next;
            s=s->next;
        }
        f=s->next;
        s->next=nullptr;
        s=nullptr;
        while(f){
            next=f->next;
            f->next=s;
            s=f;
            f=next;
        }
        f=head;
        while(f && s){
            next=f->next;
            f->next=s;
            s=s->next;
            f=f->next;
            f->next=next;
            f=f->next;
        }
    }
};