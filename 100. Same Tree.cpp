// 100. Same Tree

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
    bool chk(TreeNode *a,TreeNode *b){
        if(!a && !b)
            return 1;
        if(!a || !b)
            return 0;
        if(a->val!=b->val)
            return 0;
        return 1;
    }
    bool isSameTree(TreeNode* p, TreeNode* q){
        queue<TreeNode*> q1,q2;
        TreeNode *a,*b;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            a=q1.front();
            b=q2.front();
            q1.pop(); q2.pop();
            if(!chk(a,b))
                return 0;
            if(!a)
                continue;
            q1.push(a->left);
            q1.push(a->right);
            q2.push(b->left);
            q2.push(b->right);
        }
        if(q1.empty() && q2.empty())
            return 1;
        return 0;
    }
};