// 114. Flatten Binary Tree to Linked List

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
    void flatten(TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        TreeNode *t;
        while(root){
            if(root->left){
                t=root->left;
                while(t->right)
                    t=t->right;
                t->right=root->right;
                root->right=root->left;
                root->left=nullptr;
            }
            root=root->right;
        }
    }
};