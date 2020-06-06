// 1448. Count Good Nodes in Binary Tree

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
class Solution {
public:
    int fn(TreeNode *root,int val){
        if(!root)
            return 0;
        int ctr=0;
        if(root->val>=val)
            ctr+=1;
        ctr+=fn(root->left,max(val,root->val));
        ctr+=fn(root->right,max(val,root->val));
        return ctr;
    }
    int goodNodes(TreeNode* root){
        int ctr=fn(root,INT_MIN);
        return ctr;
    }
    
};