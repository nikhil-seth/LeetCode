// 94. Binary Tree Inorder Traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v;
        stack<TreeNode*> s;
        while(1){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(s.empty())
                break;
            root=s.top();
            s.pop();
            v.push_back(root->val);
            root=root->right;
        }
        return v;
    }
};