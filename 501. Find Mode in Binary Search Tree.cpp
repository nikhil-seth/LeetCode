// 501. Find Mode in Binary Search Tree

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
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int c,mc=0;
    TreeNode *prev=nullptr;
    void freq(TreeNode *root){
        if(!root)
            return;
        freq(root->left);
        if(prev && prev->val==root->val)
            c+=1;
        else
            c=1;
        prev=root;
        mc=max(mc,c);
        freq(root->right);
    }
    void mode(TreeNode *root,vector<int> &v){
        if(!root)
            return;
        mode(root->left,v);
        if(prev && prev->val==root->val)
            c+=1;
        else
            c=1;
        if(c==mc)
            v.push_back(root->val);
        prev=root;
        mode(root->right,v);
    }
    vector<int> findMode(TreeNode* root){
        freq(root);
        prev=nullptr;
        //cout<<mc<<endl;
        vector<int> v;
        mode(root,v);
        return v;
    }
};
