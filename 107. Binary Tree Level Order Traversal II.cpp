// 107. Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> v;
        if(!root)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        v.push_back(vector<int>(0));
        int i=0;
        while(!q.empty()){
            root=q.front();
            q.pop();
            if(!root){
                i++;
                if(q.empty())
                    break;
                v.push_back(vector<int>(0));
                q.push(nullptr);
            }
            else{
                v[i].push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};