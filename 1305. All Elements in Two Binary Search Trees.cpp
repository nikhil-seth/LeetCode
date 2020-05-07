// 1305. All Elements in Two Binary Search Trees
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
    vector<int> v;
    void fn(stack<TreeNode*> &s,TreeNode *&root){
        root=s.top();
        s.pop();
        v.push_back(root->val);
        root=root->right;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
        stack<TreeNode*> s1,s2;
        while(1){
            while(root1){
                s1.push(root1);
                root1=root1->left;
            }
            while(root2){
                s2.push(root2);
                root2=root2->left;
            }
            if(!s1.empty() && !s2.empty()){
                if(s1.top()->val>=s2.top()->val)
                    fn(s2,root2);
                else
                    fn(s1,root1);
            }
            else if(!s1.empty())
                fn(s1,root1);
            else if(!s2.empty())
                fn(s2,root2);
            else
                break;
        }
        return v;
    }
};
