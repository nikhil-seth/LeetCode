// 508. Most Frequent Subtree Sum

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
    int fn(TreeNode *root,unordered_map<int,int> &m){
        if(!root)
            return 0;
        int ts=fn(root->left,m);
        ts+=fn(root->right,m);
        ts+=root->val;
        m[ts]+=1;
        return ts;
    }
    vector<int> findFrequentTreeSum(TreeNode* root){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        unordered_map<int,int> m;
        fn(root,m);
        int x=0;
        vector<int> v;
        for(auto c:m){
            if(x<c.second){
                x=c.second;
                v.clear();
                v.push_back(c.first);
            }
            else if(x==c.second)
                v.push_back(c.first);
        }
        return v;
    }
};
        
