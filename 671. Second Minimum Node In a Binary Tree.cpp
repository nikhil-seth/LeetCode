// 671. Second Minimum Node In a Binary Tree

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
    int findSecondMinimumValue(TreeNode* root){
        if(!root) return -1;
        long best,best2=LONG_MAX;
        best=root->val;
        stack<TreeNode*> s;
        while(1){
            while(root){
                //cout<<root->val<<endl;
                if(root->val>best && root->val<best2){
                    best2=root->val;
                    root=nullptr;
                }
                // best>root->val Ho ni sakta kuki root node is min.
                else if(best==root->val){
                    s.push(root);
                    root=root->left;
                }
                else
                    root=nullptr;
            }
            if(s.empty())
                break;
            root=s.top();
            s.pop();
            root=root->right;
        }
        return best2==LONG_MAX?-1:best2;
    }
};
