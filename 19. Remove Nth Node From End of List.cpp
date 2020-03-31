//19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k=n+1;
        ListNode *l,*m;
        l=m=head;
        while(k-- && l)
            l=l->next;
        //cout<<k<<endl;
        if(l==nullptr && k!=-1){
            // 1st elem needs to be removed.
            head=head->next;
            delete(m);
            return head;
        }
        while(l!=nullptr){
            l=l->next;
            m=m->next;
        }
        l=m->next;
        m->next=l->next;
        delete(l);
        return head;
    }
};