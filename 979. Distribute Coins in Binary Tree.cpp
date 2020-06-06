// 979. Distribute Coins in Binary Tree

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
    int ans=0;
    int dfs(TreeNode *root){
        if(!root)
            return 0;
        int a,b;
        a=0;
        if(root->left)
            a+=dfs(root->left);
        if(root->right)
            a+=dfs(root->right);
        a-=1;
        a+=root->val;
        ans+=abs(a);
        return a;
    }
    int distributeCoins(TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        ans=0;
        dfs(root);
        return ans;
    }
};
    