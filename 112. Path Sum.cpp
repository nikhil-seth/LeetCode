// 112. Path Sum

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
    bool hasPathSum(TreeNode* root, int sum){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<pair<TreeNode*,int>> s;
        pair<TreeNode*,int> p;
        while(1){
            while(root){
                s.push(make_pair(root,sum));
                sum-=root->val;
                root=root->left;
            }
            if(s.empty())
                return 0;
            p=s.top();
            s.pop();
            root=p.first;
            sum=p.second-root->val;
            if(!root->left && !root->right && sum==0)
                return 1;
            root=root->right;
        }
        return 0;
    }
};
            