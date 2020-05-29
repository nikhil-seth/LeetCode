// 1161. Maximum Level Sum of a Binary Tree
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
    int maxLevelSum(TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        queue<TreeNode*> q;
        int ts,l,s,cl;
        s=INT_MIN,l=0,cl=0,ts=0;
        q.push(root);
        while(!q.empty()){
            int ctr=q.size();
            ts=0;
            cl+=1;
            while(ctr--){
                root=q.front();
                q.pop();
                ts+=root->val;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            if(ts>s)
                l=cl,s=ts;
        }
        return l;
    }
};
