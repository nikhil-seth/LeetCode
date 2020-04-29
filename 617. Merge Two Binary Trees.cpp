// 617. Merge Two Binary Trees

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
        // Iterative Approach.
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!t1)
            return t2;
        if(!t2)
            return t1;
        stack<pair<TreeNode*,TreeNode*>> s;
        pair<TreeNode*,TreeNode*> p;
        TreeNode *temp=t1;
        s.push(make_pair(t1,t2));
        while(!s.empty()){
            p=s.top();
            s.pop();
            t1=p.first;
            t2=p.second;
            t1->val+=t2->val;
            if(t1->left && t2->left)
                s.push(make_pair(t1->left,t2->left));
            else if(t2->left)
                t1->left=t2->left;
            if(t1->right && t2->right)
                s.push(make_pair(t1->right,t2->right));
            else if(t2->right)
                t1->right=t2->right;
        }
        return temp;
    }
};
