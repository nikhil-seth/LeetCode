// 25. Reverse Nodes in k-Group

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* rev(ListNode *head,ListNode *prev){
    ListNode *next;
    if(!head)
        return head;
    while(head){
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev=nullptr,*curr,*curr2,*temp,*h,*t2;
        if(!head || k==1)
            return head;
        curr=head;
        while(1){
            int x=k;
            curr2=curr;
            while(x>1 && curr2){
                curr2=curr2->next;
                x--;
            }
            if(x>1 || !curr2)
                break;
            t2=curr2->next;
            curr2->next=nullptr;
            temp=rev(curr,t2);
            if(!prev)
                h=temp;
            else
                prev->next=temp;
            prev=curr;
            curr=t2;
        }
        return h;
    }
};
