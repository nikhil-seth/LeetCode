// 515. Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v;
        if(!root)
            return v;
        queue<TreeNode*> q;
        int len,val;
        q.push(root);
        while(!q.empty()){
            len=q.size();
            val=INT_MIN;
            while(len--){
                root=q.front();
                val=max(val,root->val);
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            v.push_back(val);
        }
        return v;
    }
};