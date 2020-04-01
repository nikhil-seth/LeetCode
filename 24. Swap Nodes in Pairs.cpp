//24. Swap Nodes in Pairs

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *prev=nullptr,*c1,*c2,*h;
        c1=head;
        while(c1 && c1->next){
            c2=c1->next;
            c1->next=c2->next;
            c2->next=c1;
            if(prev)
                prev->next=c2;
            else
                h=c2;
            prev=c1;
            c1=c1->next;
        }
        return h;
    }
};
