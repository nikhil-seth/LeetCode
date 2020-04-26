// 404. Sum of Left Leaves

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
        int sumOfLeftLeaves(TreeNode* root){
            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
            if(!root)
                return 0;
            int val=0;
            stack<TreeNode*> s;
            while(1){
                while(root){
                    s.push(root);
                    if(root->left && !root->left->left && !root->left->right)
                        val+=root->left->val;
                    root=root->left;
                }
                if(s.empty())
                    break;
                root=s.top();
                s.pop();
                root=root->right;
            }
            return val;
        }
    };
