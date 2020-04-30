// 563. Binary Tree Tilt

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
    int ts;
    int fn(TreeNode *root){
        if(!root)
            return 0;
        int a,b;
        a=fn(root->left);
        b=fn(root->right);
        ts+=abs(a-b);
        return a+b+root->val;
    }
    
public:
    int findTilt(TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        ts=0;
        fn(root);
        return ts;
    }
};
