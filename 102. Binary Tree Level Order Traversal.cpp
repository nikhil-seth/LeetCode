// 102. Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> v;
        if(!root)
            return v;
        vector<int> v2;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            root=q.front();
            q.pop();
            if(!root){
                v.push_back(v2);
                if(q.empty())
                    break;
                v2.clear();
                q.push(nullptr);
            }
            else{
                v2.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        return v;
    }
};