//61. Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
            return head;
        ListNode *curr=head,*temp2;
        int len=0;
        while(curr){
            curr=curr->next;
            len++;
            if(curr && !curr->next)
                temp2=curr;
        }
        k=k%len;
        if(!k)
            return head;
        // We got actual k.
        ListNode *prev;
        prev=curr=head;
        while(k-- && curr)
            curr=curr->next;
        if(curr)
            curr=curr->next;
        while(curr){
            curr=curr->next;
            prev=prev->next;
        }
        temp2->next=head;
        head=prev->next;
        prev->next=nullptr;
        return head;
    }
};
