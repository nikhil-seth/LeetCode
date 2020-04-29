// 226. Invert Binary Tree

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
    TreeNode* invertTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        TreeNode *prev,*x,*head=root;
        prev=root;
        stack<TreeNode*> s;
        do{
            while(root){
                s.push(root);
                root=root->left;
            }
            while(!root && !s.empty()){
                root=s.top();
                if(!root->right || prev==root->right){
                    x=root->left;
                    root->left=root->right;
                    root->right=x;
                    prev=root;
                    root=nullptr;
                    s.pop();
                }
                else
                    root=root->right;
            }
        }while(!s.empty());
        return head;
    }
};
