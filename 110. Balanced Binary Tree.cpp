// 110. Balanced Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool fn(TreeNode* root,int &v){
        if(!root){
            v=0;
            return 1;
        }
        int a,b;
        if(!fn(root->left,a))
            return 0;
        if(!fn(root->right,b))
            return 0;
        //cout<<root->val<<' '<<a<<' '<<b<<endl;
        if(abs(a-b)<=1){
            v=max(a,b)+1;
            return 1;
        }
        return 0;
    }
    bool isBalanced(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int x;
        return fn(root,x);
    }
};