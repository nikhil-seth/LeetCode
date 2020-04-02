//445. Add Two Numbers II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
pair<ListNode*,int> fn(ListNode *a,ListNode *b){
    if(!a)
        return {nullptr,0};
    if(!a->next){
        a->val+=b->val;
        int v=a->val/10;
        a->val=a->val%10;
        return {a,v};
    }
    pair<ListNode*,int> px;
    px=fn(a->next,b->next);
    a->val=a->val+b->val+px.second;
    px.second=a->val/10;
    (a->val)%=10;
    px.first=a;
    return px;
}
pair<ListNode*,int> fn2(ListNode *a,ListNode *b,int len){
    pair<ListNode*,int> px;
    if(len==0)
        return fn(a,b);
    px=fn2(a->next,b,len-1);
    a->val+=px.second;
    px.second=a->val/10;
    a->val%=10;
    px.first=a;
    return px;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        int len=0;
        ListNode *curr=l1;
        while(curr){
            len++;
            curr=curr->next;
        }
        curr=l2;
        while(curr){
            len--;
            curr=curr->next;
        }
        pair<ListNode*,int> px;
        if(len>=0)
            px=fn2(l1,l2,len);
        else
            px=fn2(l2,l1,-len);
        if(px.second){
            ListNode *nn=new ListNode(px.second);
            nn->next=px.first;
            px.first=nn;
        }
        return px.first;
    }
};