// 257. Binary Tree Paths

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
    string fn(vector<int> &x){
        string s;
        for(auto c:x){
            s.append(to_string(c));
            s.append("->");
        }
        s.pop_back();
        s.pop_back();
        return s;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        vector<int> x;
        stack<TreeNode*> s;
        TreeNode *prev=nullptr;
        do{
            while(root){
                s.push(root);
                x.push_back(root->val);
                root=root->left;
            }
            while(!root && !s.empty()){
                root=s.top();
                if(!root->left && !root->right)
                    v.push_back(fn(x));
                if(!root->right || prev==root->right){
                    s.pop();
                    x.pop_back();
                    prev=root;
                    root=nullptr;
                }
                else
                    root=root->right;
            }
        }while(!s.empty());
        return v;
    }
};
