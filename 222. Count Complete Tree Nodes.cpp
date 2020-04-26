// 222. Count Complete Tree Nodes

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
    int countNodes(TreeNode* root){
        if(!root)
            return 0;
        int ld,rd;
        ld=rd=0;
        TreeNode *t=root->left;
        while(t){
            t=t->left;
            ld+=1;
        }
        t=root->right;
        while(t){
            t=t->right;
            rd+=1;
        }
        if(ld==rd){
            // Matlab Perfect BT h.
            return (1<<ld+1)-1;
        }
        else{
            return countNodes(root->left)+countNodes(root->right)+1;
        }
    }
};
