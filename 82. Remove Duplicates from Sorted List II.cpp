//82. Remove Duplicates from Sorted List II

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *p=nullptr,*c,*c2;
        c=head;
        head=nullptr;
        while(c && c->next){
            if(c->val == c->next->val){
                int temp=c->val;
                while(c && c->val==temp){
                    c2=c;
                    c=c->next;
                    delete(c2);
                }
                continue;
            }
            if(p){
                p->next=c;
                p=p->next;
            }
            else
                head=p=c;
            c=c->next;
        }
        if(c){
            if(p){
                p->next=c;
                p=p->next;
            }
            else
                head=p=c;
        }
        if(p)
            p->next=nullptr;
        return head;
    }
};
  