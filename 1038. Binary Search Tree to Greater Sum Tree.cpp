// 1038. Binary Search Tree to Greater Sum Tree
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
    TreeNode* bstToGst(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        TreeNode *x=root;
        int val=0;
        stack<TreeNode*> s;
        while(1){
            while(root){
                s.push(root);
                root=root->right;
            }
            if(s.empty())
                break;
            root=s.top();
            s.pop();
            val+=root->val;
            root->val=val;
            root=root->left;
        }
        return x;
    }
};
