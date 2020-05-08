// 1110. Delete Nodes And Return Forest
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
    vector<TreeNode*> v;
    TreeNode* fn(TreeNode *root,vector<int> &arr){
        if(!root)
            return root;
        root->left=fn(root->left,arr);
        root->right=fn(root->right,arr);
        if(binary_search(arr.begin(),arr.end(),root->val)){
            if(root->left)
                v.push_back(root->left);
            if(root->right)
                v.push_back(root->right);
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
        sort(to_delete.begin(),to_delete.end());
        root=fn(root,to_delete);
        if(root)
            v.push_back(root);
        return v;
    }
};
