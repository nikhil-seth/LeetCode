// 230. Kth Smallest Element in a BST

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
    int kthSmallest(TreeNode* root, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<TreeNode*> s;
        while(1){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(s.empty())
                break;
            k--;
            root=s.top();
            s.pop();
            if(!k)  return root->val;
            root=root->right;
        }
        return 0;
    }
};