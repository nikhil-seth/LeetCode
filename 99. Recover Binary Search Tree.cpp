// 99. Recover Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    void recoverTree(TreeNode* root){
        stack<TreeNode*> s;
        TreeNode *a=nullptr,*b,*prev=nullptr;
        while(1){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(s.empty())   break;
            root=s.top();
            s.pop();
            if(prev && prev->val>root->val){
                if(a){
                    b=root;
                    break;
                }
                else{
                    a=prev;
                    b=root;
                }
            }
            prev=root;
            root=root->right;
        }
        int temp=a->val;
        a->val=b->val;
        b->val=temp;
    }
};