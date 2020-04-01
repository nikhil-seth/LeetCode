//328. Odd Even Linked List


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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd,*even,*temp,*eh;
        if(!head || !head->next)
            return head;
        odd=head;
        eh=even=head->next;
        temp=head->next->next;
        while(temp){
            odd->next=temp;
            odd=odd->next;
            if(!temp->next)
                break;
            temp=temp->next;
            even->next=temp;
            even=even->next;
            temp=temp->next;
        }
        odd->next=eh;
        even->next=nullptr;
        return head;
    }
};
