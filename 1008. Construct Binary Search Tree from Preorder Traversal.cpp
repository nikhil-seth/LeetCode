// 1008. Construct Binary Search Tree from Preorder Traversal

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
    TreeNode* bstFromPreorder(vector<int>& preorder){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<TreeNode*> s;
        TreeNode *root=nullptr,*temp=nullptr,*x;
        for(auto c:preorder){
            x=new TreeNode(c);
            if(s.empty())
                root=x;
            else if(s.top()->val>c)
                s.top()->left=x;
            else{
                while(!s.empty() && s.top()->val<c){
                    temp=s.top();
                    s.pop();
                }
                temp->right=x;
            }
            s.push(x);
        }
        return root;
    }
};