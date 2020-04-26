// 637. Average of Levels in Binary Tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<double> v;
        double d;
        int len=1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            root=q.front();
            q.pop();
            if(!root){
                d/=len;
                v.push_back(d);
                len=q.size();
                if(q.empty())
                    break;
                q.push(nullptr);
                d=0;
            }
            else{
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                d+=root->val;
            }
        }
        return v;
    }
};