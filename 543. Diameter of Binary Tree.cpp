// 543. Diameter of Binary Tree

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
    int dia=0;
public:
    int fn(TreeNode *root){
        if(!root)
            return 0;
        int a,b;
        a=b=0;
        a=fn(root->left);
        b=fn(root->right);
        dia=max(dia,a+b+1);
        return max(a,b)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        dia=0;
        fn(root);
        if(dia)
            return dia-1;
        return 0;
    }
};
