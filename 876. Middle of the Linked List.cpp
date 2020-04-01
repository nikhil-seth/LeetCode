//876. Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return head;
        ListNode *p,*c;
        p=c=head;
        while(p->next!=nullptr){
            c=c->next;
            p=p->next;
            if(p->next)
                p=p->next;
        }
        return c;
    }
};