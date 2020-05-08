// 1315. Sum of Nodes with Even-Valued Grandparent

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
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root){
        if(!root)
            return 0;
        if(root->val%2!=0)
            return sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
        int ans=0;
        if(root->left){
            if(root->left->left)
                ans+=root->left->left->val;
            if(root->left->right)
                ans+=root->left->right->val;
            ans+=sumEvenGrandparent(root->left);
        }
        if(root->right){
            if(root->right->left)
                ans+=root->right->left->val;
            if(root->right->right)
                ans+=root->right->right->val;
            ans+=sumEvenGrandparent(root->right);
        }
        return ans;
    }
};

        