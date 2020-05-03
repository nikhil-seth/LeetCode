// 687. Longest Univalue Path

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
    int fn(TreeNode *root,int &ans){
        if(!root || (!root->left && !root->right)) return 0;
        int l=fn(root->left,ans);
        int r=fn(root->right,ans);
        l=(root->left &&  root->left->val==root->val)?l+1:0;
        r=(root->right && root->right->val==root->val)?r+1:0;
        ans=max(ans,l+r);
        return max(l,r);
    }
public:
    int longestUnivaluePath(TreeNode* root){
        int ans=0;
        fn(root,ans);
        return ans;
    }
};
auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();