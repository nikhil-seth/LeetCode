//2. Add Two Numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,val;
        if(!l1 && !l2)
            return l1;
        ListNode *h,*nn,*prev;
        h=nn=prev=nullptr;
        while(l1 ||  l2 || carry){
            val=0;
            if(l1){
                val+=l1->val;
                l1=l1->next;
            }
            if(l2){
                val+=l2->val;
                l2=l2->next;
            }
            val+=carry;
            carry=val/10;
            val%=10;
            nn=new ListNode(val);
            if(!prev)
                prev=h=nn;
            else{
                prev->next=nn;
                prev=prev->next;
            }
        }
        return h;
    }
};