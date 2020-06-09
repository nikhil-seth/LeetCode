// 1457. Pseudo-Palindromic Paths in a Binary Tree

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
    void fn(TreeNode *root,vector<int> &v){
        if(!root) return;
        v[root->val]+=1;
        if(!root->left && !root->right){
            int ctr=0;
            for(int i=0;i<=9;i+=1){
                if(v[i]%2!=0) ctr+=1;
            }
            if(ctr<=1) ans+=1;
        }
        else{
            fn(root->left,v);
            fn(root->right,v);
        }
        v[root->val]-=1;
    }
    int pseudoPalindromicPaths (TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v(10,0);
        fn(root,v);
        return ans;
    }
};