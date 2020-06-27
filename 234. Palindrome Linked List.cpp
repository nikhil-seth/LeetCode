//234. Palindrome Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!head || !head->next) return 1;
        ListNode *s,*f,*prev=nullptr;
        s=f=head;
        while(f && f->next){
            f=f->next->next;
            prev=s;
            s=s->next;
        }
        prev->next=nullptr;
        prev=nullptr,f=s;
        while(f){
            s=f->next;
            f->next=prev;
            prev=f;
            f=s;
        }
        while(head && prev && head->val==prev->val)
            head=head->next,prev=prev->next;
        if(head && prev)
            return 0;
        return 1;
    }
};
