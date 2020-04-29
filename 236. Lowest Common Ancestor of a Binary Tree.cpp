// 236. Lowest Common Ancestor of a Binary Tree

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<pair<TreeNode*,int>> s;
        s.push(make_pair(root,2));
        bool of=0;
        int state;
        pair<TreeNode*,int> pa;
        TreeNode *lca=nullptr,*child=nullptr;
        while(!s.empty()){
            //cout<<s.top().first->val<<' '<<s.top().second<<endl;
            pa=s.top();
            root=pa.first;
            state=pa.second;
            if(state!=0){
                if(state==2){
                    //Both Pending, we'll check for root.
                    if(root==p || root==q){
                        if(of)
                            return lca;
                        else{
                            of=1;
                            lca=root;
                        }
                    }
                    child=root->left;
                }
                else
                    child=root->right;
                s.pop();
                s.push(make_pair(root,state-1));
                if(child)
                    s.push(make_pair(child,2));
            }
            else{
                root=s.top().first;
                s.pop();
                if(lca==root && of)
                    lca=s.top().first;
            }
        }
        return lca;
    }
};
