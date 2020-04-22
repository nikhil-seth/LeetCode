// 111. Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right)
            return 1;
        int val=INT_MAX;
        if(root->left)
            val=min(val,minDepth(root->left));
        if(root->right)
            val=min(val,minDepth(root->right));
        return val+=1;
    }
};
