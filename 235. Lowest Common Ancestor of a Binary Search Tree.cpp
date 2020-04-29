// 235. Lowest Common Ancestor of a Binary Search Tree

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int pval=p->val,qval=q->val,rval;
        while(root){
            rval=root->val;
            if(rval<pval && rval<qval)
                root=root->right;
            else if(rval>pval && rval>qval)
                root=root->left;
            else
                return root;
        }
        return nullptr;
    }
};
