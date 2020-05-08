// 1339. Maximum Product of Splitted Binary Tree

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
    long long total=0,res,sum,mod=1e9+7;
    long long fn(TreeNode* root){
        if(!root) return 0;
        sum=root->val+fn(root->left)+fn(root->right);
        res=max(res,(total-sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root){
        stack<TreeNode*> s;
        TreeNode *x=root;
        while(1){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(s.empty()) break;
            root=s.top(); s.pop();
            total+=root->val;
            root=root->right;
        }
        fn(x);
        res%=mod;
        return res;
    }
};
