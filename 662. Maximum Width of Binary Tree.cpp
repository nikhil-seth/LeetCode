// 662. Maximum Width of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root){
        if(!root)
            return 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push(make_pair(root,1));
       unsigned long long v,len,d=0,pd=0,left=0,ans=0;
        while(!q.empty()){
            len=q.size();
            d+=1;
            while(len--){
                v=q.front().second;
                root=q.front().first;
                q.pop();
                if(!root)
                    continue;
                if(d!=pd){
                    pd=d;
                    left=v;
                }
                ans=max(ans,v-left+1);
                v*=2;
                q.push({root->left,v});
                q.push({root->right,v+1});
            }
        }
        return ans;
    }
};
