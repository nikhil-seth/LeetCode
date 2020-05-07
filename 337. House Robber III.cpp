// 337. House Robber III

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
    pair<int,int> fn(TreeNode *root){
        pair<int,int> pl,pr,n;
        n=make_pair(0,0);
        if(!root)
            return n;
        pl=fn(root->left);
        pr=fn(root->right);
        // Now Case, when we don't take root, this will be first one.
        n.first=max(pl.first,pl.second)+max(pr.first,pr.second);
        n.second=root->val+pl.first+pr.first;
        return n;
    }
    int rob(TreeNode* root){
        pair<int,int> x=fn(root);
        return max(x.first,x.second);
    }
};
