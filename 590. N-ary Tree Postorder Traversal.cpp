// 590. N-ary Tree Postorder Traversal

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
    vector<int> postorder(Node* root) {
        stack<pair<Node*,int>> s;
        int x;
        vector<int> v;
        while(1){
            while(root){
                s.push({root,0});
                root=(root->children.size()==0)?nullptr:root->children[0];
            }
            if(s.empty())
                break;
            root=s.top().first;
            x=s.top().second+1;
            s.pop();
            if(x>=root->children.size()){
                v.push_back(root->val);
                root=nullptr;
            }
            else{
                s.push({root,x});
                root=root->children[x];
            }
        }
        return v;
    }
};
