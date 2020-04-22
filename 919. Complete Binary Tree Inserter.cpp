// 919. Complete Binary Tree Inserter

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
    TreeNode *rootx,*t,*x;
    queue<TreeNode*> q;
public:
    CBTInserter(TreeNode* root) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        rootx=root;
        while(!q.empty())
            q.pop();
        q.push(rootx);
        while(!q.empty()){
            x=q.front();
            if(x->left && x->right){
                q.push(x->left);
                q.push(x->right);
                q.pop();
            }
            else{
                if(x->left)
                    q.push(x->left);
                break;
            }
        }
    }   
    int insert(int v){
        t=new TreeNode(v);
        x=q.front();
        if(!x->left)
            x->left=t;
        else{
            x->right=t;
            q.pop();
        }
        q.push(t);
        return x->val;
    }
    TreeNode* get_root() {
        return rootx;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */