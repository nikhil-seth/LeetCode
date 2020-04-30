// 513. Find Bottom Left Tree Value

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
    void fn(TreeNode *root,int d,int ans[]){
        if(!root)
            return;
        fn(root->left,d+1,ans);
        fn(root->right,d+1,ans);
        if(ans[1]<d){
            ans[1]=d;
            ans[0]=root->val;
        }
    }
    int findBottomLeftValue(TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int ans[2]={root->val,0};
        fn(root,0,ans);
        return ans[0];
    }
};