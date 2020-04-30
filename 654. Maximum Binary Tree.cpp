// 654. Maximum Binary Tree

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
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<TreeNode*> s;
        TreeNode *x,*y;
        for(auto c:nums){
            x=new TreeNode(c);
            if(s.empty() || c<s.top()->val)
                s.push(x);
            else{
                y=s.top();
                s.pop();
                while(!s.empty() && s.top()->val<=c){
                    s.top()->right=y;
                    y=s.top();
                    s.pop();
                }
                x->left=y;
                s.push(x);
            }
        }
        y=s.top();
        s.pop();
        while(!s.empty()){
            s.top()->right=y;
            y=s.top();
            s.pop();
        }
        return y;
    }
};
