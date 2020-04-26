// 1022. Sum of Root To Leaf Binary Numbers

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
    int sumRootToLeaf(TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int val=0,tval=0;
        stack<TreeNode*> s;
        TreeNode* prev;
        do{
            while(root){
                val=val*2+root->val;
                s.push(root);
                root=root->left;
            }
            while(!root && !s.empty()){
                root=s.top();
                if(!root->right && !root->left)
                    tval+=val;
                if(!root->right || prev==root->right){
                    s.pop();
                    val=(val-root->val)/2;
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
