//101. Symmetric Tree

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
   bool isSymmetric(TreeNode* root){
       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        TreeNode *a,*b;
        while(!q.empty()){
            a=q.front();
            q.pop();
            b=q.front();
            q.pop();
            if(!a && !b)
                continue;
            if(!a || !b)
                return 0;
            if(a->val!=b->val)
                return 0;
            q.push(a->right);
            q.push(b->left);
            q.push(a->left);
            q.push(b->right);
        }
        return 1;
    }
};
