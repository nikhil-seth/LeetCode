// 752. Open the Lock

class Solution {
public:
    int openLock(vector<string>& deadends, string target){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        unordered_set<string> s(deadends.begin(),deadends.end());
        unordered_set<string> head,tail;
        string qt="0000";
        if(s.find(qt)!=s.end()) return -1;
        head.insert(qt);
        tail.insert(target);
        int init=1;
        while(!head.empty() && !tail.empty()){
            if(head.size()>tail.size())
                swap(head,tail);
            unordered_set<string> temp;
            for(auto x:head){
                for(int i=0;i<4;i+=1){
                    char c=x[i];
                    x[i]=c+1;
                    if(x[i]==58)
                        x[i]=48;
                    if(tail.find(x)!=tail.end()) return init;
                    if(s.find(x)==s.end())
                        temp.insert(x);
                    x[i]=c-1;
                    if(x[i]==47)
                        x[i]=57;
                    if(tail.find(x)!=tail.end()) return init;
                    if(s.find(x)==s.end())
                        temp.insert(x);
                    x[i]=c;
                }
            }
            swap(head,temp);
            init+=1;
        }
        return -1;
    }
};
