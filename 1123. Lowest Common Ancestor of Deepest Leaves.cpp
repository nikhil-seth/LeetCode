// 1123. Lowest Common Ancestor of Deepest Leaves

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
    pair<TreeNode*,int> fn(TreeNode* root){
        if(!root) return {nullptr,0};
        pair<TreeNode*,int> l,r;
        l=fn(root->left);
        r=fn(root->right);
        if(l.second==r.second)
            return {root,l.second+1};
        else if(l.second>r.second){
            l.second+=1;
            return l;
        }
        else{
            r.second+=1;
            return r;
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root){
        pair<TreeNode*,int> x=fn(root);
        return x.first;
    }
};