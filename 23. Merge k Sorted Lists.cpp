//23. Merge k Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *merge(ListNode *a,ListNode *b){
    if(!a)
        return b;
    if(!b)
        return a;
    if(a->val<b->val){
        a->next=merge(a->next,b);
        return a;
    }
    else{
        b->next=merge(a,b->next);
        return b;
    }
}
ListNode* fn(vector<ListNode*>&lists,int l,int r){
    if(l>r)
        return nullptr;
    if(l==r)
        return lists[l];
    int mid=(l+r)/2;
    ListNode *a,*b;
    a=fn(lists,l,mid);
    b=fn(lists,mid+1,r);
    return merge(a,b);
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        int len=lists.size();
        if(!len)
            return nullptr;
        return fn(lists,0,len-1);
    }
};