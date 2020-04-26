// 129. Sum Root to Leaf Numbers

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

    int sumNumbers(TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int tval=0,val=0;
        stack<TreeNode*> s;
        TreeNode *prev=nullptr;
        do{
            while(root){
                s.push(root);
                val=val*10+root->val;
                root=root->left;
            }
            while(!root && !s.empty()){
                root=s.top();
                if(!root->left && !root->right)
                    tval+=val;
                if(!root->right || prev==root->right){
                    s.pop();
                    val=(val-root->val)/10;
                    prev=root;
                    root=nullptr;
                }
                else
                    root=root->right;
            }
        }while(!s.empty());
        return tval;
    }
};
