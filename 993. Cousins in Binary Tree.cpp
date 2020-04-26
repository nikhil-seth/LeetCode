// 993. Cousins in Binary Tree

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
    bool isCousins(TreeNode* root, int x, int y) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        queue<pair<TreeNode*,TreeNode*>> q;
        TreeNode *p1,*p2;
        p1=p2=nullptr;
        pair<TreeNode*,TreeNode*> p;
        int ls=0;
        q.push(make_pair(root,nullptr));
        while(!q.empty()){
            ls=q.size();
            while(ls){
                p=q.front();
                q.pop();
                if(p.first->val==x)
                    p1=p.second;
                if(p.first->val==y)
                    p2=p.second;
                root=p.first;
                if(root->left)
                    q.push(make_pair(root->left,root));
                if(root->right)
                    q.push(make_pair(root->right,root));
                ls--;
            }
            if(p1 && p2){
                if(p1==p2)
                    return 0;
                return 1;
            }
            if(p1 || p2)
                return 0;
        }
        return 0;
    }
};