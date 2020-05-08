// 109. Convert Sorted List to Binary Search Tree

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    TreeNode* fn(ListNode *&h,int ctr){
        if(ctr<=0)
            return nullptr;
        TreeNode *t,*root;
        t=fn(h,ctr/2);
        root=new TreeNode(h->val);
        h=h->next;
        root->left=t;
        root->right=fn(h,ctr-ctr/2-1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head){
        ListNode *x=head;
        int ctr=0;
        while(x){
            ctr+=1;
            x=x->next;
        }
        return fn(head,ctr);
    }
};