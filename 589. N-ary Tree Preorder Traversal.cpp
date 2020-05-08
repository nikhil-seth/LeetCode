// 589. N-ary Tree Preorder Traversal
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    vector<int> ans;
    void fn(Node *root){
        if(!root) return;
        ans.push_back(root->val);
        for(auto c:root->children)
            fn(c);
    }
    vector<int> preorder(Node* root){
        fn(root);
        return ans;
    }
};
