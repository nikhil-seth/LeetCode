// 1028. Recover a Tree From Preorder Traversal
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
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        stack<TreeNode*> s;
        TreeNode *x,*y=nullptr;
        int ctr=0,n=0;
        for(int i=0;i<S.length();){
            if(isdigit(S[i])){
                n=0;
                while(isdigit(S[i]) && i<S.length())
                    n=n*10+S[i++]-'0';
                x=new TreeNode(n);
                while(ctr<s.size())
                    s.pop();
                if(!s.empty()){
                    y=s.top();
                    if(y && y->left)
                        y->right=x;
                    else if(y)
                        y->left=x;
                }
                s.push(x);
                ctr=0;
            }
            i+=1;
            }
        }
        while(!s.empty()){
            x=s.top();
            s.pop();
        }
        return x;
    }
};
