// 559. Maximum Depth of N-ary Tree

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
    int maxDepth(Node* root){
        int lvl=0,len;
        if(!root)
            return lvl;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            lvl+=1;
            len=q.size();
            while(len--){
                root=q.front();
                q.pop();
                for(auto c:root->children)
                    q.push(c);
            }
        }
        return lvl;
    }
};
