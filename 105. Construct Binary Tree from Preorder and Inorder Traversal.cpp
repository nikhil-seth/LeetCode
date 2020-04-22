// 105. Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(preorder.size()==0)
            return nullptr;
        stack<TreeNode*> s;
        int i=1,j=0;
        bool f=0;
        TreeNode *root,*t=new TreeNode(preorder[0]);
        root=t;
        s.push(t);
        while(i<preorder.size()){
            if(!s.empty() && s.top()->val==inorder[j]){
                // We got it.
                t=s.top();
                s.pop();
                f=1;
                j++;
            }
            else{
                if(f==1){
                    f=0;
                    t->right=new TreeNode(preorder[i]);
                    t=t->right;
                    s.push(t);
                }
                else{
                    t->left=new TreeNode(preorder[i]);
                    t=t->left;
                    s.push(t);
                }
                i+=1;
            }
        }
        return root;
    }
};