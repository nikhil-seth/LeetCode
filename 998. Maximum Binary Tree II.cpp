// 998. Maximum Binary Tree II

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
    Solution(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val){
        if(!root){
            TreeNode *x=new TreeNode(val);
            return x;
        }
        else if(root->val<val){
            TreeNode *x=new TreeNode(val);
            x->left=root;
            return x;
        }
        root->right=insertIntoMaxTree(root->right,val);
        return root;
    }
};
