//203. Remove Linked List Elements

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr,*prev=nullptr;
        curr=head;
        head=nullptr;
        while(curr){
            if(curr->val==val)
                curr=curr->next;
            else{
                if(prev){
                    prev->next=curr;
                    prev=prev->next;
                    curr=curr->next;
                    prev->next=nullptr;
                }
                else{
                    head=prev=curr;
                    curr=curr->next;
                    prev->next=nullptr;
                }
            }
        }
        return head;
    }
};