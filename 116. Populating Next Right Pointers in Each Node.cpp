// 116. Populating Next Right Pointers in Each Node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root){
        Node *curr,*prev,*head;
        curr=root;
        prev=head=nullptr;
        while(curr){
            if(curr->left){
                if(prev)
                    prev->next=curr->left;
                if(!prev)
                    head=curr->left;
                prev=curr->left->next=curr->right;
            }
            curr=curr->next;
            if(!curr){
                curr=head;
                prev=head=nullptr;
            }
        }
        return root;
    }
};