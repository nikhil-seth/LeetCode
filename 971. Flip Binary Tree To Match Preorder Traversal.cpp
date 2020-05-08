// 971. Flip Binary Tree To Match Preorder Traversal
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage){
        stack<TreeNode*> s;
        vector<int> v,v2;
        v2.push_back(-1);
        TreeNode *temp;
        int i=0;
        while(1){
            while(root){
                s.push(root);
                if(root->val!=voyage[i++])
                    return v2;
                if(root->left && root->right && root->left->val!=voyage[i]){
                        temp=root->left;
                        root->left=root->right;
                        root->right=temp;
                        v.push_back(root->val);
                }
                root=root->left;
            }
            if(s.empty())
                break;
            root=s.top();
            s.pop();
            root=root->right;
        }
        return v;
    }
};
