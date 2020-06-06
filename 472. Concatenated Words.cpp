// 472. Concatenated Words

class Node{
public:
    char c;
    bool word;
    Node *next,*child; // next-> next elem, child->iska baccha.
    Node(char c){word=false,this->c=c,next=child=nullptr;}
    bool isWord(){return word;}
    void setWord(){word=1;}
};
void insert(Node **head,const string &w){
    Node **q=head;
    Node *p=nullptr;
    for(const auto &c:w){
        // We'll go by every letter.
        for(p=*q;p;p=p->next){
            if(p->c==c)
                break;
            q=&p->next; // This is making q=next elem of p's location.
        }
        if(p==nullptr){
            // If we don't find it.
            p=new Node(c);
            *q=p; // this made q=p
        }
        q=&p->child; // q is pointing to p ka child.
    }
    if(p!=nullptr) p->setWord(); // ?
}
bool helper(Node *head,const string &w,int idx,int words){
    if(idx>=w.length() && words>1)
        return 1;
    // Agar word end hogya aur word is made by more than 2 words, toh it is concat.
    int sz=w.length();
    Node *p=head;
    for(int i=idx;i<sz;i+=1){
        while(p!=nullptr){
            if(p->c==w[i])
                break;
            p=p->next;
        }
        if(p==nullptr) // Not Found
            return 0;
        if(p->isWord()){
            if(helper(head,w,i+1,words+1))
                return 1;
        }
        p=p->child;
    }
    return 0;
}
class Solution {
    Node *head;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        head=nullptr;
        for(const auto &x:words){
            if(x.empty()) continue;
            insert(&head,x);
            cout<<head->c<<' ';
        }
        vector<string> ans;
        for(const auto &x:words){
            if(x.empty()) continue;
            if(helper(head,x,0,0))
                ans.push_back(x);
        }
        return ans;
    }
};
