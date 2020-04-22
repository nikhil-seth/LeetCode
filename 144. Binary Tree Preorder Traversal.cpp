// 144. Binary Tree Preorder Traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v;
        stack<TreeNode*> s;
        while(1){
            while(root){
                v.push_back(root->val);
                s.push(root);
                root=root->left;
            }
            if(s.empty())
                break;
            root=s.top();
            s.pop();
            root=root->right;
        }
        return v;
    }
};
