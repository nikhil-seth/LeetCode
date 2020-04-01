//83. Remove Duplicates from Sorted List

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
        ListNode *c1=head,*c2,*temp;
        while(c1){
            c2=c1->next;
            while(c2 && c2->val==c1->val){
                temp=c2;
                c2=c2->next;
                delete(temp);
            }
            c1->next=c2;
            c1=c2;
        }
        return head;
    }
};