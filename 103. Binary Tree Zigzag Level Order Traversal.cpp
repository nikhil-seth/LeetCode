// 103. Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> v;
        if(!root)
            return v;
        queue<TreeNode*> q;
        q.push(nullptr);
        q.push(root);
        int i=-1,j;
        bool f=1;
        while(!q.empty()){
            root=q.front();
            q.pop();
            if(!root){
                if(q.empty())
                    break;
                f=!f;
                v.push_back(vector<int>(q.size()));
                i+=1;
                if(f==0)
                    j=0;
                else
                    j=q.size()-1;
                q.push(nullptr);
            }
            else{
                //cout<<root->val<<' ';
                v[i][j]=root->val;
                if(f)
                    j-=1;
                else
                    j+=1;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        return v;
    }
};