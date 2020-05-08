// 814. Binary Tree Pruning

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
    TreeNode* fn(TreeNode *root,int &val){
        if(!root)
            return root;
        if(!root->left && !root->right){
            val=root->val;
            if(root->val)
                return root;
            return nullptr;
        }
        int x=0,y=0;
        root->left=fn(root->left,x);
        root->right=fn(root->right,y);
        val=x+y+root->val;
        if(val>0)
            return root;
        return nullptr;
    }
    TreeNode* pruneTree(TreeNode* root){
        int x=0;
        return fn(root,x);
    }
};
