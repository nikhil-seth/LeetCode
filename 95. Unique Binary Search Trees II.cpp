// 95. Unique Binary Search Trees II
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

class Solution {
public:
    vector<TreeNode*> fn(int s,int e){
        vector<TreeNode*> v;
        if(s>e){
            v.push_back(nullptr);
            return v;
        }
        for(int i=s;i<=e;i++){
            vector<TreeNode*> lt=fn(s,i-1);
            vector<TreeNode*> rt=fn(i+1,e);
            for(int j=0;j<lt.size();j++){
                for(int k=0;k<rt.size();k++){
                    TreeNode *x=new TreeNode(i);
                    x->left=lt[j];
                    x->right=rt[k];
                    v.push_back(x);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return vector<TreeNode*>(0);
        return fn(1,n);
    }
};
