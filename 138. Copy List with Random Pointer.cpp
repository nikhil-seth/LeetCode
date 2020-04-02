//138. Copy List with Random Pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        if(!head)
            return head;
        m[nullptr]=nullptr;
        Node *curr;
        curr=head;
        while(curr){
            Node *nn=new Node(curr->val);
            m[curr]=nn;
            curr=curr->next;
        }
        curr=head;
        while(curr){
            m[curr]->next=m[curr->next];
            m[curr]->random=m[curr->random];
            curr=curr->next;
        }
        return m[head];
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node *head2,*curr,*temp;
        curr=head;
        while(curr){
            Node *nn=new Node(curr->val);
            nn->next=curr->random;
            curr->random=nn;
            curr=curr->next;
        }
        // We Made all nodes.
        curr=head;
        head2=curr->random;
        while(curr){
            if(curr->random->next)
                curr->random->random=curr->random->next->random;
            else
                curr->random->random=nullptr;
             curr=curr->next;
        }
    
        curr=head;
        while(curr){
            temp=curr->random;
            curr->random=temp->next;
            if(curr->next)
                temp->next=curr->next->random;
            else
                temp->next=nullptr;
            curr=curr->next;
        }
        return head2;
    }
};