// https://leetcode.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root,long l=LONG_MIN,long r=LONG_MAX){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<TreeNode*> s;
        TreeNode *prev=nullptr;
        while(1){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(s.empty())
                return 1;
            root=s.top();
            if(prev && root->val<=prev->val)
                return 0;
            prev=root;
            root=root->right;
            s.pop();
        }
        return 1;
    }
};