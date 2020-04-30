// 623. Add One Row to Tree

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
    TreeNode* addOneRow(TreeNode* root, int v, int d){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!root)
            return root;
        if(d==1){
            TreeNode *x=new TreeNode(v);
            x->left=root;
            return x;
        }
        TreeNode *x,*h=root;
        int lvl=1,len;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            len=q.size();
            while(len--){
                root=q.front();
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                if(lvl==d-1){
                    x=new TreeNode(v);
                    x->left=root->left;
                    root->left=x;
                    x=new TreeNode(v);
                    x->right=root->right;
                    root->right=x;
                }
            }
            lvl+=1;
        }
        return h;
    }
};