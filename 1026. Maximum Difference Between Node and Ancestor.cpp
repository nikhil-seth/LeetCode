// 1026. Maximum Difference Between Node and Ancestor

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
class Solution {
    struct st{
        int maxval,minval;
        TreeNode *t;
        st(TreeNode *&x,int &a,int &b){
            t=x;
            maxval=a;
            minval=b;
        }
    };
    void cpy(TreeNode *&root,int &a,int &b,st &x){
        root=x.t;
        a=x.maxval;
        b=x.minval;
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int val=INT_MIN;
        stack<st> s;
        int maxval=INT_MIN,minval=INT_MAX;
        while(1){
            while(root){
                maxval=max(maxval,root->val);
                minval=min(minval,root->val);
                s.push(st(root,maxval,minval));
                root=root->left;
            }
            if(s.empty())
               break;
            cpy(root,maxval,minval,s.top());
            s.pop();
            if(!root->left && !root->right)
                val=max(val,maxval-minval);
            root=root->right;
        }
        return val;
    }
};
