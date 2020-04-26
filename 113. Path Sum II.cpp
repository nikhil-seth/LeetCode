// 113. Path Sum II

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
    vector<vector<int>> pathSum(TreeNode* root, int sum){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> v;
        vector<int> x;
        stack<pair<TreeNode*,int>> s;
        pair<TreeNode*,int> p;
        TreeNode* prev;
        do{
            while(root){
                s.push(make_pair(root,sum));
                sum-=root->val;
                x.push_back(root->val);
                root=root->left;
            }
            while(!root && !s.empty()){
                p=s.top();
                root=p.first;
                sum=p.second-root->val;
                if(!root->right && !root->left && sum==0)
                    v.push_back(x);
                if(!root->right || prev==root->right){
                    // Now, we need to remove.
                    x.pop_back();
                    s.pop();
                    prev=root;
                    root=nullptr;
                }
                else
                    root=root->right;
            }
        }while(!s.empty());
        return v;
    }
};