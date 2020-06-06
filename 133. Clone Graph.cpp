// 133. Clone Graph
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        unordered_map<int,Node*> m;
        fn(node,m);
        return m[node->val];
    }
    void fn(Node *node,unordered_map<int,Node*> &m){
        Node *nn=new Node(node->val);
        m[node->val]=nn;
        for(auto x:node->neighbors){
            if(m.find(x->val)==m.end())
                fn(x,m);
            nn->neighbors.push_back(m[x->val]);
        }
    }
};