// 863. All Nodes Distance K in Binary Tree
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
    unordered_map<TreeNode*,int> m;
    vector<int> v;
        
public:
    int find(TreeNode *root,TreeNode *target){
        if(!root)
            return -1;
        if(root==target){
            m[target]=0;
            return 0;
        }
        int l,r;
        l=find(root->left,target);
        if(l>=0){
            // Found at dist.
            m[root]=l+1;
            return l+1;
        }
        r=find(root->right,target);
        if(r>=0){
            m[root]=r+1;
            return r+1;
        }
        return -1;
    }
    void dfs(TreeNode *root,int k,int l){
        if(!root)
            return;
        if(m.find(root)!=m.end())
            l=m[root];
        if(l==k)
            v.push_back(root->val);
        dfs(root->left,k,l+1);
        dfs(root->right,k,l+1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        v.clear();
        m.clear();
        find(root,target);
        dfs(root,K,0);
        return v;
    }
};