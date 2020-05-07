// 958. Check Completeness of a Binary Tree

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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sn=0;
        while(!q.empty()){
            root=q.front();
            q.pop();
            if(!root){
                if(!sn) sn=1;
                continue;
            }
            else if(sn) return 0;
            q.push(root->left);
            q.push(root->right);
        }
        return 1;
    }
};