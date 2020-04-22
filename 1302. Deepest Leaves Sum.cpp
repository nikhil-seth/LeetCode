// 1302. Deepest Leaves Sum

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
    int deepestLeavesSum(TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!root)
            return 0;
        int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            root=q.front();
            q.pop();
            if(!root){
                if(q.empty())
                    break;
                sum=0;
                q.push(nullptr);
            }
            else{
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                sum+=root->val;
            }
        }
        return sum;
    }
};