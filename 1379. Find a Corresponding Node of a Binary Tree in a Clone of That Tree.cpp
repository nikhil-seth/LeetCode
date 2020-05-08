// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    bool isEqual(TreeNode *a,TreeNode *b){
        if(!a && !b) return 1;
        if(!a || !b || a->val!=b->val) return 0;
        return isEqual(a->left,b->left) && isEqual(a->right,b->right);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<TreeNode*> s;
        TreeNode *root=cloned;
        while(1){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(s.empty())
                break;
            root=s.top();
            s.pop();
            if(root->val==target->val)// && isEqual(root,target))
                return root;
            root=root->right;
        }
        return nullptr;
    }
};
