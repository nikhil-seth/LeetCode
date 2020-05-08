// 951. Flip Equivalent Binary Trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;
        if(root1->val!=root2->val)
            return false;
        return (flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right))||(flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left));
    }
};