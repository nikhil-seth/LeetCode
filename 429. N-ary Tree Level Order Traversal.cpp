// 429. N-ary Tree Level Order Traversal

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(!root)
            return v;
        queue<Node*> q;
        q.push(root);
        int len;
        while(!q.empty()){
            vector<int> res;
            len=q.size();
            while(len--){
                root=q.front();
                res.push_back(root->val);
                q.pop();
                for(auto c:root->children)
                    q.push(c);
            }
            v.push_back(res);
        }
        return v;
    }
};
