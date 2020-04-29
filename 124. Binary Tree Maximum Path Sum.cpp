// 124. Binary Tree Maximum Path Sum

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
    int maxval;
    int fn(TreeNode *root){
        if(!root)
            return 0;
        int l,r;
        l=max(0,fn(root->left));
        r=max(0,fn(root->right));
        maxval=max(maxval,l+r+root->val);
        return max(l,r)+root->val;
    }
public:
    int maxPathSum(TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        maxval=INT_MIN;
        fn(root);
        return maxval;
    }
    
        
};
        