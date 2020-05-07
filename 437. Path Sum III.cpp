// 437. Path Sum III

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
    unordered_map<int,int> m;
    int fn(TreeNode *root,int sum,int pre){
        if(!root)
            return 0;
        root->val+=pre;
        int res=0;
        if(root->val==sum)
            res+=1;
        if(m.find(root->val-sum)!=m.end())
            res+=m[root->val-sum];
        m[root->val]=m[root->val]+1;
        res+=fn(root->left,sum,root->val);
        res+=fn(root->right,sum,root->val);
        m[root->val]-=1;
        return res;
    }
    int pathSum(TreeNode* root, int sum){
        return fn(root,sum,0);
    }
};