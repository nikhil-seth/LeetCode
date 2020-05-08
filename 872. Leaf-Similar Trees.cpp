// 872. Leaf-Similar Trees

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2){
        vector<int> v;
        int i=0;
        stack<TreeNode*> s;
        while(1){
            while(root1){
                s.push(root1);
                root1=root1->left;
            }
            if(s.empty()) break;
            root1=s.top();
            s.pop();
            if(!root1->left && !root1->right)
                v.push_back(root1->val);
            root1=root1->right;
        }
        while(1){
            while(root2){
                s.push(root2);
                root2=root2->left;
            }
            if(s.empty()) break;
            root2=s.top();
            s.pop();
            if(!root2->left && !root2->right){
                if(root2->val==v[i])
                    i+=1;
                else
                    return 0;
            }
            root2=root2->right;
        }
        return 1;
    }
};

        