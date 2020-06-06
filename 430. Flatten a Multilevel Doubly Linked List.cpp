// 430. Flatten a Multilevel Doubly Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head){
        if(!head)
            return head;
        fn(head);
        return head;
    }
    Node *fn(Node *head){
        while(head){
            if(head->child){
                Node *x=fn(head->child);
                x->next=head->next;
                if(x->next)
                    x->next->prev=x;
                head->child->prev=head;
                head->next=head->child;
                head->child=nullptr;
                head=head;
            }
            if(head->next==nullptr)
                break;
            head=head->next;
        }
        return head;
    }
};