// 106. Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(postorder.size()==0)
            return nullptr;
        stack<TreeNode*> s;
        int i=postorder.size()-1,j=inorder.size()-1;
        bool f=0;
        TreeNode *root,*t=new TreeNode(postorder[i]);
        root=t;
        i-=1;
        s.push(t);
        while(i>=0){
            if(!s.empty() && s.top()->val==inorder[j]){
                f=1;
                t=s.top();
                s.pop();
                j-=1;
            }
            else{
                if(f){
                    f=0;
                    t->left=new TreeNode(postorder[i]);
                    t=t->left;
                }
                else{
                    t->right=new TreeNode(postorder[i]);
                    t=t->right;
                }
                s.push(t);
                i-=1;
            }
        }
        return root;
    }
};
