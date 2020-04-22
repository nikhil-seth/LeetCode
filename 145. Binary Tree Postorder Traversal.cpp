// 145. Binary Tree Postorder Traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode *prev=nullptr;
        do{
            while(root){
                s.push(root);
                root=root->left;
            }
            while(!root && !s.empty()){
                root=s.top();
                if(root->right==nullptr || root->right==prev){
                    v.push_back(root->val);
                    prev=root;
                    root=nullptr;
                    s.pop();
                }
                else{
                    root=root->right;
                }
            }
        }while(!s.empty());
        return v;
    }
};
    