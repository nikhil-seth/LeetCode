// 707. Design Linked List

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct ListNode{
        int val;
        ListNode *next;
    };
    ListNode *head;
    MyLinkedList() {
        head=nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode *temp=head;
        while(index>0 && temp){
            index--;
            temp=temp->next;
        }
        if(!temp)
            return -1;
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *nn=new ListNode;
        nn->val=val;
        if(!head)
            nn->next=nullptr;
        else
            nn->next=head;
        head=nn;
    
    }
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *nn=new ListNode;
        nn->val=val;
        nn->next=nullptr;
        if(!head)
            head=nn;
        else{
            ListNode *temp=head;
            while(temp->next!=nullptr)
                temp=temp->next;
            temp->next=nn;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index==0)
            addAtHead(val);
        else{
            ListNode *prev,*curr,*nn;
            curr=head;
            while(index>0 && curr){
                prev=curr;
                curr=curr->next;
                index--;
            }
            if(index>0)
                return;
            else{
                nn=new ListNode;
                nn->val=val;
                nn->next=prev->next;
                prev->next=nn;
            }
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode *prev,*curr;
        if(index==0){
            // First Node.
            prev=head;
            head=head->next;
            delete prev;
        }
        else{
            curr=head;
            while(index>0 && curr){
                index--;
                prev=curr;
                curr=curr->next;
            }
            if(index>0)
                return;
            if(prev && prev->next){
                curr=prev->next;
                prev->next=prev->next->next;
                delete curr;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */