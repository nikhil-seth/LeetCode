// 938. Range Sum of BST

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R){
        stack<TreeNode*> s;
        int val=0;
        while(1){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(s.empty())
                break;
            root=s.top();
            s.pop();
            if(root->val<=R && root->val>=L){
                val+=root->val;
                root=root->right;
            }
            else if(root->val>R)
                root=nullptr;
            else
                root=root->right;
        }
        return val;
    }
};