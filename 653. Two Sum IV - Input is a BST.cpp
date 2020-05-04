// 653. Two Sum IV - Input is a BST

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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> s1,s2;
        TreeNode *t1,*t2;
        t1=t2=root;
        while(1){
            while(t1){
                s1.push(t1);
                t1=t1->left;
            }
            while(t2){
                s2.push(t2);
                t2=t2->right;
            }
            if(s1.empty() || s2.empty())
                break;
            t1=s1.top();
            t2=s2.top();
            if(t1==t2 || t1->val>t2->val)
                break;
            if(t1->val+t2->val==k)
                return 1;
            if(t1->val+t2->val>k){
                s2.pop();
                t1=nullptr;
                t2=t2->left;
            }
            else{
                s1.pop();
                t2=nullptr;
                t1=t1->right;
            }
        }
        return 0;
    }
};