// 988. Smallest String Starting From Leaf

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
    string ans="";
    void fn(TreeNode *root,string s){
        s+='a'+root->val;
        if(!root->left && !root->right){
            // We Got Leaf Node
            reverse(s.begin(),s.end());
            if(ans=="" || ans>s)
                ans=s;
        }
        else{
            if(root->left)
                fn(root->left,s);
            if(root->right)
                fn(root->right,s);
        }
    }
    string smallestFromLeaf(TreeNode* root){
        fn(root,"");
        return ans;
    }
};
