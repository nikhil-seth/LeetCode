// 117. Populating Next Right Pointers in Each Node II

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
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        Node *prev,*curr,*head;
        curr=root;
        prev=head=nullptr;
        while(curr){
            if(curr->left){
                if(prev)
                    prev=prev->next=curr->left;
                else
                    prev=head=curr->left;
            }
            if(curr->right){
                if(prev)
                    prev=prev->next=curr->right;
                else
                    prev=head=curr->right;
            }
            curr=curr->next;
            if(!curr){
                curr=head;
                head=prev=nullptr;
            }
        }
        return root;
    }
};
