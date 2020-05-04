// 669. Trim a Binary Search Tree

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R){
        if(!root)
            return nullptr;
        if(root->val<L)
            return trimBST(root->right,L,R);
        if(root->val>R)
            return trimBST(root->left,L,R);
        root->left=trimBST(root->left,L,R);
        root->right=trimBST(root->right,L,R);
        return root;
    }
};
