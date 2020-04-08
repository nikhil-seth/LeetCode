//1290. Convert Binary Number in a Linked List to Integer
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
    int getDecimalValue(ListNode* head) {
        if(!head)
            return 0;
        int val=0;
        while(head){
            val=val*2+head->val;
            head=head->next;
        }
        return val;
    }
};