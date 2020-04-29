// 173. Binary Search Tree Iterator

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
class BSTIterator {
    stack<TreeNode*> s;
    TreeNode *x;
public:
    BSTIterator(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        while(!s.empty())
            s.pop();
        x=root;
        while(x){
            s.push(x);
            x=x->left;
        }
    }
    /** @return the next smallest number */
    int next(){
        x=s.top();
        int val=x->val;
        s.pop();
        x=x->right;
        while(x){
            s.push(x);
            x=x->left;
        }
        return val;
    }
        
    /** @return whether we have a next smallest number */
    bool hasNext(){
        return !s.empty();
    }
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */