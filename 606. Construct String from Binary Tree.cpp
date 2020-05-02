// 606. Construct String from Binary Tree

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
    string tree2str(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        string out;
        if(!root)
            return string("");
        stack<TreeNode*> s;
        set<TreeNode*> st;
        s.push(root);
        while(!s.empty()){
            root=s.top();
            if(st.find(root)==st.end()){
                st.insert(root);
                out.push_back('(');
                out.append(to_string(root->val));
                if(root->left==nullptr && root->right!=nullptr)
                    out.append("()");
                if(root->right)
                    s.push(root->right);
                if(root->left)
                    s.push(root->left);
            }
            else{
                s.pop();
                out.push_back(')');
            }
        }
        return out.substr(1,out.length()-2);
    }
};