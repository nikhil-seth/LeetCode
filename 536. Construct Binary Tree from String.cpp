// 536. Construct Binary Tree from String
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param s: a string
     * @return: a root of this tree
     */
    stack<TreeNode*> st;
    TreeNode *cn,*t;
    TreeNode * str2tree(string &s) {
    int i=0;
    while(i<s.length()){
        if(s[i]==')'){
            st.pop();
            i+=1;
        }
        else if(s[i]=='(')
            i+=1;
        else{
            int sign=1,val=0;
            if(s[i]=='-'){
                sign=-1;
                i+=1;
            }
            while(isdigit(s[i]))
                val=val*10+s[i++]-'0';
            val*=sign;
            t=new TreeNode(val);
            if(!st.empty()){
                if(st.top()->left)
                    st.top()->right=t;
                else
                    st.top()->left=t;
            }
            st.push(t);
            continue;
        }
    }
    return st.top();
}
};