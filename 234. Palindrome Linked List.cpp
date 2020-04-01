//234. Palindrome Linked List

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
    bool isPalindrome(ListNode* head) {
        ListNode *f,*s,*prev,*next;
        f=s=head;
        while(f && f->next){
            f=f->next->next;
            s=s->next;
        }
        prev=nullptr;
        while(s){
            next=s->next;
            s->next=prev;
            prev=s;
            s=next;
        }
        f=head;
        s=prev;
        while(f && s && f->val == s->val){
            f=f->next;
            s=s->next;
        }
        if(f && s)
            return 0;
        return 1;
    }
};